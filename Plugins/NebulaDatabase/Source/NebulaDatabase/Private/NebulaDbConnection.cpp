#include "NebulaDbConnection.h"

#include "Async/Async.h"
#include "HAL/PlatformProcess.h"

THIRD_PARTY_INCLUDES_START
#include <mysql.h>
THIRD_PARTY_INCLUDES_END

DEFINE_LOG_CATEGORY(LogNebulaDb);

FNebulaDbConnection::FNebulaDbConnection()
{
	// Create handle now; it's cheap and simplifies lifecycle.
	Connection = mysql_init(nullptr);
}

FNebulaDbConnection::~FNebulaDbConnection()
{
	Disconnect();
}

FNebulaDbConnection::FNebulaDbConnection(FNebulaDbConnection&& Other) noexcept
{
	Connection = Other.Connection;
	Other.Connection = nullptr;
}

FNebulaDbConnection& FNebulaDbConnection::operator=(FNebulaDbConnection&& Other) noexcept
{
	if (this != &Other)
	{
		Disconnect();
		Connection = Other.Connection;
		Other.Connection = nullptr;
	}
	return *this;
}

bool FNebulaDbConnection::IsConnected() const
{
	// mysql_ping returns 0 if connection is alive, nonzero if error.
	if (!Connection)
	{
		return false;
	}

	return (mysql_ping(Connection) == 0);
}

bool FNebulaDbConnection::Connect(const FNebulaDatabaseCredentials& Creds)
{
	if (!Connection)
	{
		Connection = mysql_init(nullptr);
		if (!Connection)
		{
			UE_LOG(LogNebulaDb, Error, TEXT("mysql_init failed"));
			return false;
		}
	}

	// Apply connection options before connecting
	unsigned int TimeoutSec = (unsigned int)FMath::Clamp(Creds.ConnectTimeoutSeconds, 1, 120);
	mysql_options(Connection, MYSQL_OPT_CONNECT_TIMEOUT, &TimeoutSec);

	// Optional: if you want automatic reconnect semantics, you can enable it,
	// but beware behavior differences across connector versions.
	// my_bool Reconnect = 1;
	// mysql_options(Connection, MYSQL_OPT_RECONNECT, &Reconnect);

	const char* Host = TCHAR_TO_UTF8(*Creds.Host);
	const char* User = TCHAR_TO_UTF8(*Creds.User);
	const char* Pass = TCHAR_TO_UTF8(*Creds.Password);
	const char* Db   = TCHAR_TO_UTF8(*Creds.Database);
	unsigned int Port = (unsigned int)Creds.Port;

	MYSQL* Result = mysql_real_connect(
		Connection,
		Host,
		User,
		Pass,
		Db,
		Port,
		nullptr,
		0
	);

	if (!Result)
	{
		FNebulaQueryResult Err;
		FillError(Err, Connection);
		UE_LOG(LogNebulaDb, Error, TEXT("Connect failed (%d): %s"), Err.ErrorCode, *Err.ErrorMessage);
		return false;
	}

	UE_LOG(LogNebulaDb, Log, TEXT("Connected to %s:%d / DB=%s"),
		*Creds.Host, Creds.Port, *Creds.Database);

	return true;
}

void FNebulaDbConnection::Disconnect()
{
	if (Connection)
	{
		mysql_close(Connection);
		Connection = nullptr;
	}
}

void FNebulaDbConnection::FillError(FNebulaQueryResult& Out, MYSQL* Conn)
{
	if (!Conn)
	{
		Out.ErrorCode = -1;
		Out.ErrorMessage = TEXT("No MYSQL connection handle.");
		return;
	}

	Out.ErrorCode = (int32)mysql_errno(Conn);
	const char* Err = mysql_error(Conn);
	Out.ErrorMessage = Err ? UTF8_TO_TCHAR(Err) : TEXT("Unknown MySQL/MariaDB error.");
}

FNebulaQueryResult FNebulaDbConnection::ExecNoResultInternal(const char* SqlUtf8)
{
	FNebulaQueryResult Out;

	if (!Connection)
	{
		Out.bSuccess = false;
		Out.ErrorCode = -1;
		Out.ErrorMessage = TEXT("Not connected (MYSQL* is null).");
		return Out;
	}

	const int QueryRes = mysql_query(Connection, SqlUtf8);
	if (QueryRes != 0)
	{
		Out.bSuccess = false;
		FillError(Out, Connection);
		return Out;
	}

	Out.bSuccess = true;
	Out.AffectedRows = (int64)mysql_affected_rows(Connection);
	return Out;
}

FNebulaQueryResult FNebulaDbConnection::ExecResultInternal(const char* SqlUtf8)
{
	FNebulaQueryResult Out;

	if (!Connection)
	{
		Out.bSuccess = false;
		Out.ErrorCode = -1;
		Out.ErrorMessage = TEXT("Not connected (MYSQL* is null).");
		return Out;
	}

	const int QueryRes = mysql_query(Connection, SqlUtf8);
	if (QueryRes != 0)
	{
		Out.bSuccess = false;
		FillError(Out, Connection);
		return Out;
	}

	MYSQL_RES* Res = mysql_store_result(Connection);

	// If Res is null, there are two possibilities:
	// 1) query didn't return data (e.g. UPDATE) -> success
	// 2) error occurred -> mysql_errno != 0
	if (!Res)
	{
		const unsigned int ErrNo = mysql_errno(Connection);
		if (ErrNo != 0)
		{
			Out.bSuccess = false;
			FillError(Out, Connection);
			return Out;
		}

		Out.bSuccess = true;
		Out.AffectedRows = (int64)mysql_affected_rows(Connection);
		return Out;
	}

	const int32 NumFields = (int32)mysql_num_fields(Res);
	MYSQL_FIELD* Fields = mysql_fetch_fields(Res);

	Out.Columns.Reserve(NumFields);
	for (int32 i = 0; i < NumFields; ++i)
	{
		Out.Columns.Add(Fields[i].name ? UTF8_TO_TCHAR(Fields[i].name) : TEXT(""));
	}

	MYSQL_ROW Row;
	while ((Row = mysql_fetch_row(Res)) != nullptr)
	{
		unsigned long* Lengths = mysql_fetch_lengths(Res);

		FNebulaQueryRow UErow;

		UErow.Cells.Reserve(NumFields);

		for (int32 c = 0; c < NumFields; ++c)
		{
			if (Row[c] == nullptr)
			{
				UErow.Cells.Add(TEXT(""));
			}
			else
			{
				UErow.Cells.Add(UTF8_TO_TCHAR(Row[c]));
			}
		}

		Out.Rows.Add(MoveTemp(UErow));
	}

	mysql_free_result(Res);

	Out.bSuccess = true;
	return Out;
}

FNebulaQueryResult FNebulaDbConnection::ExecUpdate(const FString& SqlUtf16)
{
	const FTCHARToUTF8 Utf8(*SqlUtf16);
	return ExecNoResultInternal(Utf8.Get());
}

FNebulaQueryResult FNebulaDbConnection::ExecSelect(const FString& SqlUtf16)
{
	const FTCHARToUTF8 Utf8(*SqlUtf16);
	return ExecResultInternal(Utf8.Get());
}

void FNebulaDbConnection::ExecUpdateAsync(const FString& SqlUtf16, TFunction<void(FNebulaQueryResult&&)>&& Callback)
{
	// Copy SQL for background thread
	const FString SqlCopy = SqlUtf16;

	Async(EAsyncExecution::ThreadPool, [this, SqlCopy, Callback = MoveTemp(Callback)]() mutable
	{
		FNebulaQueryResult Result = ExecUpdate(SqlCopy);

		AsyncTask(ENamedThreads::GameThread, [Callback = MoveTemp(Callback), Result = MoveTemp(Result)]() mutable
		{
			Callback(MoveTemp(Result));
		});
	});
}

void FNebulaDbConnection::ExecSelectAsync(const FString& SqlUtf16, TFunction<void(FNebulaQueryResult&&)>&& Callback)
{
	const FString SqlCopy = SqlUtf16;

	Async(EAsyncExecution::ThreadPool, [this, SqlCopy, Callback = MoveTemp(Callback)]() mutable
	{
		FNebulaQueryResult Result = ExecSelect(SqlCopy);

		AsyncTask(ENamedThreads::GameThread, [Callback = MoveTemp(Callback), Result = MoveTemp(Result)]() mutable
		{
			Callback(MoveTemp(Result));
		});
	});
}