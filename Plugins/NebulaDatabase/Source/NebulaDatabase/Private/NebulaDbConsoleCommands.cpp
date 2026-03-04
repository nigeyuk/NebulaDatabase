// Copyright 2026 U4RIA Studios

#include "NebulaDbConsoleCommands.h"

#include "HAL/IConsoleManager.h"
#include "NebulaDatabase.h"
#include "NebulaDbConnection.h"
#include "NebulaDatabaseSettingsHelpers.h"
#include "NebulaDatabaseQueryResult.h"

bool FNebulaDbConsoleCommands::bRegistered = false;

static IConsoleObject* GNebulaDbSmokeTestCmd = nullptr;
static IConsoleObject* GNebulaDbSelectCmd = nullptr;
static IConsoleObject* GNebulaDbUpdateCmd = nullptr;

static void LogResultPreview(const FNebulaQueryResult& R, int32 MaxRowsToPrint = 10, int32 MaxColsToPrint = 16)
{
	if (!R.bSuccess)
	{
		UE_LOG(LogNebulaDatabase, Error, TEXT("[NebulaDB] FAIL (%d): %s"), R.ErrorCode, *R.ErrorMessage);
		return;
	}

	UE_LOG(LogNebulaDatabase, Warning, TEXT("[NebulaDB] OK. Rows=%d Cols=%d Affected=%lld"),
		R.Rows.Num(), R.Columns.Num(), R.AffectedRows);

	// Print header
	if (R.Columns.Num() > 0)
	{
		FString Header = TEXT("Columns: ");
		const int32 ColCount = FMath::Min(R.Columns.Num(), MaxColsToPrint);
		for (int32 c = 0; c < ColCount; ++c)
		{
			Header += R.Columns[c];
			if (c + 1 < ColCount) Header += TEXT(" | ");
		}
		if (R.Columns.Num() > MaxColsToPrint)
		{
			Header += TEXT(" | ...");
		}
		UE_LOG(LogNebulaDatabase, Warning, TEXT("%s"), *Header);
	}

	// Print rows
	const int32 RowCount = FMath::Min(R.Rows.Num(), MaxRowsToPrint);
	for (int32 r = 0; r < RowCount; ++r)
	{
		const auto& Row = R.Rows[r].Cells;

		FString Line = FString::Printf(TEXT("Row %d: "), r);
		const int32 ColCount = FMath::Min(Row.Num(), MaxColsToPrint);
		for (int32 c = 0; c < ColCount; ++c)
		{
			Line += Row[c];
			if (c + 1 < ColCount) Line += TEXT(" | ");
		}
		if (Row.Num() > MaxColsToPrint)
		{
			Line += TEXT(" | ...");
		}

		UE_LOG(LogNebulaDatabase, Warning, TEXT("%s"), *Line);
	}

	if (R.Rows.Num() > MaxRowsToPrint)
	{
		UE_LOG(LogNebulaDatabase, Warning, TEXT("[NebulaDB] (truncated output; showing %d/%d rows)"),
			MaxRowsToPrint, R.Rows.Num());
	}
}

void FNebulaDbConsoleCommands::Register()
{
	if (bRegistered)
	{
		return;
	}
	bRegistered = true;

	GNebulaDbSmokeTestCmd = IConsoleManager::Get().RegisterConsoleCommand(
		TEXT("NebulaDB.SmokeTest"),
		TEXT("Runs a DB smoke test: connect -> SELECT 1 -> disconnect"),
		FConsoleCommandDelegate::CreateStatic(&FNebulaDbConsoleCommands::SmokeTest),
		ECVF_Default
	);

	GNebulaDbSelectCmd = IConsoleManager::Get().RegisterConsoleCommand(
		TEXT("NebulaDB.Select"),
		TEXT("Run a SELECT query. Usage: NebulaDB.Select <SQL...>"),
		FConsoleCommandWithArgsDelegate::CreateStatic(&FNebulaDbConsoleCommands::SelectCommand),
		ECVF_Default
	);

	GNebulaDbUpdateCmd = IConsoleManager::Get().RegisterConsoleCommand(
		TEXT("NebulaDB.Update"),
		TEXT("Run an UPDATE/INSERT/DELETE/DDL query. Usage: NebulaDB.Update <SQL...>"),
		FConsoleCommandWithArgsDelegate::CreateStatic(&FNebulaDbConsoleCommands::UpdateCommand),
		ECVF_Default
	);

	UE_LOG(LogNebulaDatabase, Warning, TEXT("NebulaDB console commands registered: NebulaDB.SmokeTest, NebulaDB.Select, NebulaDB.Update"));
}

void FNebulaDbConsoleCommands::Unregister()
{
	if (!bRegistered)
	{
		return;
	}
	bRegistered = false;

	auto& CM = IConsoleManager::Get();

	if (GNebulaDbSmokeTestCmd) { CM.UnregisterConsoleObject(GNebulaDbSmokeTestCmd); GNebulaDbSmokeTestCmd = nullptr; }
	if (GNebulaDbSelectCmd)    { CM.UnregisterConsoleObject(GNebulaDbSelectCmd);    GNebulaDbSelectCmd = nullptr; }
	if (GNebulaDbUpdateCmd)    { CM.UnregisterConsoleObject(GNebulaDbUpdateCmd);    GNebulaDbUpdateCmd = nullptr; }
}

FString FNebulaDbConsoleCommands::JoinSql(const TArray<FString>& Args)
{
	// Join all args into a single SQL string (console splits on spaces)
	FString Sql;
	for (int32 i = 0; i < Args.Num(); ++i)
	{
		if (i > 0) Sql += TEXT(" ");
		Sql += Args[i];
	}
	return Sql.TrimStartAndEnd();
}

void FNebulaDbConsoleCommands::SmokeTest()
{
	const FNebulaDatabaseCredentials Creds = NebulaDatabaseSettingsHelpers::GetCredentials();

	UE_LOG(LogNebulaDatabase, Warning, TEXT("[NebulaDB SmokeTest] Host=%s Port=%d DB=%s User=%s PwLen=%d"),
		*Creds.Host, Creds.Port, *Creds.Database, *Creds.User, Creds.Password.Len());

	FNebulaDbConnection Conn;
	if (!Conn.Connect(Creds))
	{
		UE_LOG(LogNebulaDatabase, Error, TEXT("[NebulaDB SmokeTest] FAIL: Connect"));
		return;
	}

	FNebulaQueryResult R = Conn.ExecSelect(TEXT("SELECT 1 AS one;"));
	if (!R.bSuccess)
	{
		UE_LOG(LogNebulaDatabase, Error, TEXT("[NebulaDB SmokeTest] FAIL: Query (%d) %s"),
			R.ErrorCode, *R.ErrorMessage);
		Conn.Disconnect();
		return;
	}

	const FString Value =
		(R.Rows.Num() > 0 && R.Rows[0].Cells.Num() > 0) ? R.Rows[0].Cells[0] : TEXT("<no data>");

	UE_LOG(LogNebulaDatabase, Warning, TEXT("[NebulaDB SmokeTest] PASS: SELECT 1 -> %s"), *Value);

	Conn.Disconnect();
	UE_LOG(LogNebulaDatabase, Warning, TEXT("[NebulaDB SmokeTest] Disconnected"));
}

void FNebulaDbConsoleCommands::SelectCommand(const TArray<FString>& Args)
{
	const FString Sql = JoinSql(Args);
	if (Sql.IsEmpty())
	{
		UE_LOG(LogNebulaDatabase, Error, TEXT("Usage: NebulaDB.Select <SQL...>"));
		return;
	}

	const FNebulaDatabaseCredentials Creds = NebulaDatabaseSettingsHelpers::GetCredentials();

	FNebulaDbConnection Conn;
	if (!Conn.Connect(Creds))
	{
		UE_LOG(LogNebulaDatabase, Error, TEXT("[NebulaDB.Select] Connect FAILED"));
		return;
	}

	FNebulaQueryResult R = Conn.ExecSelect(Sql);
	LogResultPreview(R);

	Conn.Disconnect();
}

void FNebulaDbConsoleCommands::UpdateCommand(const TArray<FString>& Args)
{
	const FString Sql = JoinSql(Args);
	if (Sql.IsEmpty())
	{
		UE_LOG(LogNebulaDatabase, Error, TEXT("Usage: NebulaDB.Update <SQL...>"));
		return;
	}

	const FNebulaDatabaseCredentials Creds = NebulaDatabaseSettingsHelpers::GetCredentials();

	FNebulaDbConnection Conn;
	if (!Conn.Connect(Creds))
	{
		UE_LOG(LogNebulaDatabase, Error, TEXT("[NebulaDB.Update] Connect FAILED"));
		return;
	}

	FNebulaQueryResult R = Conn.ExecUpdate(Sql);

	if (!R.bSuccess)
	{
		UE_LOG(LogNebulaDatabase, Error, TEXT("[NebulaDB] FAIL (%d): %s"), R.ErrorCode, *R.ErrorMessage);
	}
	else
	{
		UE_LOG(LogNebulaDatabase, Warning, TEXT("[NebulaDB] OK. AffectedRows=%lld"), R.AffectedRows);
	}

	Conn.Disconnect();
}