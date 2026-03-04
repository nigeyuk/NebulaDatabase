#pragma once

#include "CoreMinimal.h"
#include "NebulaDatabaseQueryResult.generated.h"

USTRUCT(BlueprintType)
struct NEBULADATABASE_API FNebulaQueryRow
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category="Database")
	TArray<FString> Cells;
};

USTRUCT(BlueprintType)
struct NEBULADATABASE_API FNebulaQueryResult
{
	GENERATED_BODY()

	/** True if the query executed successfully */
	UPROPERTY(BlueprintReadOnly, Category="Database")
	bool bSuccess = false;

	/** MariaDB/MySQL error code */
	UPROPERTY(BlueprintReadOnly, Category="Database")
	int32 ErrorCode = 0;

	/** Error message */
	UPROPERTY(BlueprintReadOnly, Category="Database")
	FString ErrorMessage;

	/** Affected rows (UPDATE/INSERT/DELETE) */
	UPROPERTY(BlueprintReadOnly, Category="Database")
	int64 AffectedRows = 0;

	/** Column names */
	UPROPERTY(BlueprintReadOnly, Category="Database")
	TArray<FString> Columns;

	/** Result rows */
	UPROPERTY(BlueprintReadOnly, Category="Database")
	TArray<FNebulaQueryRow> Rows;
};