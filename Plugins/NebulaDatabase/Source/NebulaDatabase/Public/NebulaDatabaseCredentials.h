// Copyright 2026 U4RIA Studios

#pragma once

#include "CoreMinimal.h"
#include "NebulaDatabaseCredentials.generated.h"

USTRUCT(BlueprintType)
struct NEBULADATABASE_API FNebulaDatabaseCredentials
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DatabaseCredentials")
	FString Host = TEXT("127.0.0.1");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DatabaseCredentials")
	FString User = TEXT("root");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DatabaseCredentials", meta=(PasswordField=true))
	FString Password;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DatabaseCredentials")
	FString Database = TEXT("mysql");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DatabaseCredentials")
	int32 Port = 3306;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DatabaseCredentials", meta=(ClampMin="1", ClampMax="120"))
	int32 ConnectTimeoutSeconds = 5;
};