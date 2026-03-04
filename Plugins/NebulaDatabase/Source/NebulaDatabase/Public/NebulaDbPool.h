#pragma once

#include "CoreMinimal.h"
#include "NebulaDbConnection.h"
#include "NebulaDatabaseCredentials.h"
#include "NebulaDatabaseQueryResult.h"

class NEBULADATABASE_API FNebulaDbPool
{
public:
	FNebulaDbPool();
	~FNebulaDbPool();

	bool Initialize(const FNebulaDatabaseCredentials& Creds, int32 PoolSize = 4);
	void Shutdown();

	bool IsInitialized() const { return bInitialized; }

	// Async API (preferred)
	void SelectAsync(const FString& Sql, TFunction<void(FNebulaQueryResult&&)>&& Callback);
	void UpdateAsync(const FString& Sql, TFunction<void(FNebulaQueryResult&&)>&& Callback);

private:
	TSharedPtr<FNebulaDbConnection> AcquireBlocking();
	void Release(TSharedPtr<FNebulaDbConnection> Conn);

private:
	FCriticalSection Mutex;
	FEvent* AvailableEvent = nullptr;

	TArray<TSharedPtr<FNebulaDbConnection>> FreeConnections;
	TArray<TSharedPtr<FNebulaDbConnection>> AllConnections;

	FNebulaDatabaseCredentials Credentials;
	bool bInitialized = false;
	bool bShuttingDown = false;
};