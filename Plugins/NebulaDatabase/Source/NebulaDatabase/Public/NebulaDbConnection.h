#pragma once

#include "CoreMinimal.h"
#include "NebulaDatabaseCredentials.h"
#include "NebulaDatabaseQueryResult.h"

THIRD_PARTY_INCLUDES_START
#include <mysql.h>
THIRD_PARTY_INCLUDES_END

DECLARE_LOG_CATEGORY_EXTERN(LogNebulaDb, Log, All);

/**
 * Thin RAII wrapper around MariaDB/MySQL C API connection (MYSQL*).
 *
 * Threading:
 * - You MAY call Connect/Disconnect/Exec* on a background thread.
 * - Do NOT use the same FNebulaDbConnection instance concurrently from multiple threads.
 *   (Use one per thread or use a pool.)
 */
class NEBULADATABASE_API FNebulaDbConnection
{
public:
	FNebulaDbConnection();
	~FNebulaDbConnection();

	// Non-copyable (MYSQL* ownership)
	FNebulaDbConnection(const FNebulaDbConnection&) = delete;
	FNebulaDbConnection& operator=(const FNebulaDbConnection&) = delete;

	// Movable
	FNebulaDbConnection(FNebulaDbConnection&& Other) noexcept;
	FNebulaDbConnection& operator=(FNebulaDbConnection&& Other) noexcept;

	/** Connect using credentials. Returns true on success. */
	bool Connect(const FNebulaDatabaseCredentials& Creds);

	/** Disconnect if connected. Safe to call multiple times. */
	void Disconnect();

	/** True if we have an open connection handle. */
	bool IsConnected() const;

	/** Execute INSERT/UPDATE/DELETE/DDL. */
	FNebulaQueryResult ExecUpdate(const FString& SqlUtf16);

	/** Execute SELECT query and fetch full result set. */
	FNebulaQueryResult ExecSelect(const FString& SqlUtf16);

	/** Async helpers (no game-thread blocking). Callback always runs on the game thread. */
	void ExecUpdateAsync(const FString& SqlUtf16, TFunction<void(FNebulaQueryResult&&)>&& Callback);
	void ExecSelectAsync(const FString& SqlUtf16, TFunction<void(FNebulaQueryResult&&)>&& Callback);

private:
	static void FillError(FNebulaQueryResult& Out, MYSQL* Conn);

	/** Internal execute that doesn’t fetch results (used for update). */
	FNebulaQueryResult ExecNoResultInternal(const char* SqlUtf8);

	/** Internal execute that fetches results (used for select). */
	FNebulaQueryResult ExecResultInternal(const char* SqlUtf8);

private:
	MYSQL* Connection = nullptr;
};