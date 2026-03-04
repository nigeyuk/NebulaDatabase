// Copyright 2026 U4RIA Studios

#pragma once

#include "CoreMinimal.h"

class NEBULADATABASE_API FNebulaDbConsoleCommands
{
public:
	static void Register();
	static void Unregister();

private:
	static void SmokeTest();

	// New: arbitrary query runners
	static void SelectCommand(const TArray<FString>& Args);
	static void UpdateCommand(const TArray<FString>& Args);

	static FString JoinSql(const TArray<FString>& Args);

	static bool bRegistered;
};
