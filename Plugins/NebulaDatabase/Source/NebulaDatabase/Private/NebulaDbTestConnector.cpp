// Copyright 2026 U4RIA Studios

#include "NebulaDbTestConnector.h"

#include "NebulaDbConnection.h"
#include "NebulaDatabaseSettingsHelpers.h"
#include "NebulaDatabaseQueryResult.h"
#include "NebulaDatabase.h" // for LogNebulaDatabase (or swap to LogNebulaDb if you prefer)

THIRD_PARTY_INCLUDES_START
#include <mysql.h>
THIRD_PARTY_INCLUDES_END

void FNebulaDbTestConnector::RunOnce()
{
	const FNebulaDatabaseCredentials Creds = NebulaDatabaseSettingsHelpers::GetCredentials();

	UE_LOG(LogNebulaDatabase, Warning, TEXT("[NebulaDB Test] Connecting to %s:%d DB=%s User=%s"),
		*Creds.Host, Creds.Port, *Creds.Database, *Creds.User);

	FNebulaDbConnection Conn;
	UE_LOG(LogNebulaDatabase, Warning, TEXT("[NebulaDB Test] Password length: %d"),
	Creds.Password.Len());
	
	if (!Conn.Connect(Creds))
	{
		UE_LOG(LogNebulaDatabase, Error, TEXT("[NebulaDB Test] Connect FAILED"));
		return;
	}

	// Client/server info (works once connected)
	UE_LOG(LogNebulaDatabase, Warning, TEXT("[NebulaDB Test] Client: %s"), UTF8_TO_TCHAR(mysql_get_client_info()));

	// NOTE: mysql_get_server_info takes MYSQL*; our wrapper doesn't expose it.
	// So we'll just run a quick query to prove round-trip.
	FNebulaQueryResult R = Conn.ExecSelect(TEXT("SELECT 1 AS one;"));

	if (!R.bSuccess)
	{
		UE_LOG(LogNebulaDatabase, Error, TEXT("[NebulaDB Test] Query FAILED (%d): %s"),
			R.ErrorCode, *R.ErrorMessage);
	}
	else
	{
		const FString Value =
			(R.Rows.Num() > 0 && R.Rows[0].Cells.Num() > 0) ? R.Rows[0].Cells[0] : TEXT("<no data>");

		UE_LOG(LogNebulaDatabase, Warning, TEXT("[NebulaDB Test] Query OK. SELECT 1 -> %s"), *Value);
	}

	Conn.Disconnect();
	UE_LOG(LogNebulaDatabase, Warning, TEXT("[NebulaDB Test] Disconnected"));
}
