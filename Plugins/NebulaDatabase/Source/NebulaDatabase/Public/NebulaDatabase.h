// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FNebulaDbPool;

DECLARE_LOG_CATEGORY_EXTERN(LogNebulaDatabase, Log, All);

class FNebulaDatabaseModule : public IModuleInterface
{
public:
	static FNebulaDatabaseModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FNebulaDatabaseModule>("NebulaDatabase");
	}

	static bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("NebulaDatabase");
	}

	// IModuleInterface
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/** Access the pool (valid after StartupModule; may be uninitialized if you don't auto-connect). */
	FNebulaDbPool& GetPool();

	/** Optional: initialize pool now (useful for dedicated server startup). */
	bool InitializePool(int32 PoolSize = 4);

	/** Optional: shutdown pool now. */
	void ShutdownPool();

private:
	TUniquePtr<FNebulaDbPool> Pool;
	bool bPoolInitialized = false;
};