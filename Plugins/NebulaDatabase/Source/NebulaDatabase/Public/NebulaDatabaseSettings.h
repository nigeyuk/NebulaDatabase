// Copyright 2026 U4RIA Studios

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "NebulaDatabaseSettings.generated.h"

/**
 * Config-backed settings for NebulaDatabase.
 *
 * Loaded from:
 *   Config/DefaultNebulaDatabase.ini  (defaults)
 *   Saved/Config/<Platform>/NebulaDatabase.ini (user overrides)
 *
 * Section:
 *   [NebulaDatabase.DatabaseCredentials]
 */
UCLASS(Config=NebulaDatabase, DefaultConfig)
class NEBULADATABASE_API UNebulaDatabaseSettings : public UObject
{
	GENERATED_BODY()
public:
	
	// Hostname or IP
	UPROPERTY(Config, EditAnywhere, Category="DatabaseCredentials")
	FString DatabaseHost = TEXT("127.0.0.1");
	
	// Username
	UPROPERTY(Config, EditAnywhere, Category="DatabaseCredentials")
	FString DatabaseUser = TEXT("root");
	
	// Password
	UPROPERTY(Config, EditAnywhere, Category="DatabaseCredentials")
	FString DatabasePassword;
	
	// Default database / schema name
	UPROPERTY(Config, EditAnywhere, Category="DatabaseCredentials")
	FString DatabaseName = TEXT("mysql");
	
	// Tcp Port (Generally the default port (3306))
	UPROPERTY(Config, EditAnywhere, Category="DatabaseCredentials")
	int32 DatabasePort = 3306;
	
	// Connection timeout (seconds).  Keep this small for server startup reliability.
	UPROPERTY(Config, EditAnywhere, Category="DatabaseCredentials", meta=(ClampMin="1", ClampMax="120"))
	int32 DatabaseConnectTimeoutSeconds = 5;
};
