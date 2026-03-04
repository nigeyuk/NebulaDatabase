// Copyright 2026 U4RIA Studios

#include "NebulaDbPool.h"

#include "Async/Async.h"
#include "HAL/Event.h"
#include "HAL/PlatformProcess.h"

FNebulaDbPool::FNebulaDbPool()
{
	AvailableEvent = FPlatformProcess::GetSynchEventFromPool(false);
}

FNebulaDbPool::~FNebulaDbPool()
{
	Shutdown();

	if (AvailableEvent)
	{
		FPlatformProcess::ReturnSynchEventToPool(AvailableEvent);
		AvailableEvent = nullptr;
	}
}

bool FNebulaDbPool::Initialize(const FNebulaDatabaseCredentials& Creds, int32 PoolSize)
{
	FScopeLock Lock(&Mutex);

	if (bInitialized)
	{
		return true;
	}

	bShuttingDown = false;
	Credentials = Creds;

	AllConnections.Reserve(PoolSize);
	FreeConnections.Reserve(PoolSize);

	for (int32 i = 0; i < PoolSize; ++i)
	{
		TSharedPtr<FNebulaDbConnection> Conn = MakeShared<FNebulaDbConnection>();

		if (!Conn->Connect(Creds))
		{
			// Clean up what we already created
			for (auto& C : AllConnections)
			{
				if (C.IsValid()) { C->Disconnect(); }
			}
			AllConnections.Empty();
			FreeConnections.Empty();
			bInitialized = false;
			return false;
		}

		AllConnections.Add(Conn);
		FreeConnections.Add(Conn);
	}

	bInitialized = true;
	return true;
}

void FNebulaDbPool::Shutdown()
{
	FScopeLock Lock(&Mutex);

	if (!bInitialized)
	{
		return;
	}

	bShuttingDown = true;

	// Wake any waiters so they can exit
	if (AvailableEvent)
	{
		AvailableEvent->Trigger();
	}

	for (auto& Conn : AllConnections)
	{
		if (Conn.IsValid())
		{
			Conn->Disconnect();
		}
	}

	AllConnections.Empty();
	FreeConnections.Empty();

	bInitialized = false;
}

TSharedPtr<FNebulaDbConnection> FNebulaDbPool::AcquireBlocking()
{
	while (true)
	{
		{
			FScopeLock Lock(&Mutex);

			if (bShuttingDown || !bInitialized)
			{
				return nullptr;
			}

			if (FreeConnections.Num() > 0)
			{
				return FreeConnections.Pop();
			}
		}

		// Wait briefly for a connection to return
		if (AvailableEvent)
		{
			AvailableEvent->Wait(10); // 10ms
		}
	}
}

void FNebulaDbPool::Release(TSharedPtr<FNebulaDbConnection> Conn)
{
	if (!Conn.IsValid())
	{
		return;
	}

	{
		FScopeLock Lock(&Mutex);
		if (!bInitialized || bShuttingDown)
		{
			return;
		}

		FreeConnections.Add(Conn);
	}

	if (AvailableEvent)
	{
		AvailableEvent->Trigger();
	}
}

void FNebulaDbPool::SelectAsync(const FString& Sql, TFunction<void(FNebulaQueryResult&&)>&& Callback)
{
	const FString SqlCopy = Sql;

	Async(EAsyncExecution::ThreadPool, [this, SqlCopy, Callback = MoveTemp(Callback)]() mutable
	{
		TSharedPtr<FNebulaDbConnection> Conn = AcquireBlocking();
		if (!Conn.IsValid())
		{
			FNebulaQueryResult Fail;
			Fail.bSuccess = false;
			Fail.ErrorCode = -1;
			Fail.ErrorMessage = TEXT("DB pool not initialized or shutting down.");
			AsyncTask(ENamedThreads::GameThread, [Callback = MoveTemp(Callback), Fail = MoveTemp(Fail)]() mutable
			{
				Callback(MoveTemp(Fail));
			});
			return;
		}

		FNebulaQueryResult Result = Conn->ExecSelect(SqlCopy);

		Release(Conn);

		AsyncTask(ENamedThreads::GameThread, [Callback = MoveTemp(Callback), Result = MoveTemp(Result)]() mutable
		{
			Callback(MoveTemp(Result));
		});
	});
}

void FNebulaDbPool::UpdateAsync(const FString& Sql, TFunction<void(FNebulaQueryResult&&)>&& Callback)
{
	const FString SqlCopy = Sql;

	Async(EAsyncExecution::ThreadPool, [this, SqlCopy, Callback = MoveTemp(Callback)]() mutable
	{
		TSharedPtr<FNebulaDbConnection> Conn = AcquireBlocking();
		if (!Conn.IsValid())
		{
			FNebulaQueryResult Fail;
			Fail.bSuccess = false;
			Fail.ErrorCode = -1;
			Fail.ErrorMessage = TEXT("DB pool not initialized or shutting down.");
			AsyncTask(ENamedThreads::GameThread, [Callback = MoveTemp(Callback), Fail = MoveTemp(Fail)]() mutable
			{
				Callback(MoveTemp(Fail));
			});
			return;
		}

		FNebulaQueryResult Result = Conn->ExecUpdate(SqlCopy);

		Release(Conn);

		AsyncTask(ENamedThreads::GameThread, [Callback = MoveTemp(Callback), Result = MoveTemp(Result)]() mutable
		{
			Callback(MoveTemp(Result));
		});
	});
}