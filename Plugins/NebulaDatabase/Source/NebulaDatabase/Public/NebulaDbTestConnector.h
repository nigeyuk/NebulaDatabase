// Copyright 2026 U4RIA Studios

#pragma once

#include "CoreMinimal.h"

/**
 * One-shot DB smoke test:
 * - Loads credentials from config
 * - Connects
 * - Logs client/server info + a SELECT 1
 * - Disconnects
 *
 * Safe to call from StartupModule() after libmariadb.dll is loaded.
 */
class NEBULADATABASE_API FNebulaDbTestConnector
{
public:
	static void RunOnce();
};
