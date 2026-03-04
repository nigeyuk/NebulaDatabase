// Copyright 2026 U4RIA Studios

#include "NebulaDatabase.h"
#include "NebulaDbTestConnector.h"
#include "NebulaDbConsoleCommands.h"

#include "Interfaces/IPluginManager.h"
#include "HAL/PlatformProcess.h"
#include "Misc/Paths.h"

#include "NebulaDbPool.h"
#include "NebulaDatabaseSettingsHelpers.h"

DEFINE_LOG_CATEGORY(LogNebulaDatabase);

static void* GMariaDbHandle = nullptr;

void FNebulaDatabaseModule::StartupModule()
{
	// A runonce connect / disconnect, outputs results to warning log.
	//FNebulaDbTestConnector::RunOnce();
	
#if !UE_BUILD_SHIPPING
	FNebulaDbConsoleCommands::Register();
#endif
	
	UE_LOG(LogNebulaDatabase, Warning, TEXT("NebulaDatabase: StartupModule begin"));

	// Ensure the DLL search path contains our plugin binaries folder and load libmariadb.dll explicitly.
	// This prevents delay-load/search-path nonsense.
	const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("NebulaDatabase"));
	if (Plugin.IsValid())
	{
		const FString BinDir  = FPaths::Combine(Plugin->GetBaseDir(), TEXT("Binaries/Win64"));
		const FString DllPath = FPaths::Combine(BinDir, TEXT("libmariadb.dll"));

		FPlatformProcess::AddDllDirectory(*BinDir);

		GMariaDbHandle = FPlatformProcess::GetDllHandle(*DllPath);
		if (!GMariaDbHandle)
		{
			UE_LOG(LogNebulaDatabase, Error, TEXT("NebulaDatabase: Failed to load libmariadb.dll from: %s"), *DllPath);
		}
		else
		{
			UE_LOG(LogNebulaDatabase, Warning, TEXT("NebulaDatabase: Loaded libmariadb.dll OK"));
		}
	}
	else
	{
		UE_LOG(LogNebulaDatabase, Error, TEXT("NebulaDatabase: Plugin not found via IPluginManager (DLL load path not set)"));
	}

	Pool = MakeUnique<FNebulaDbPool>();
	bPoolInitialized = false;

	// auto-connect on module startup, uncomment this.
	// For safety, many teams leave it manual and call InitializePool() from server startup code.
	//
	// InitializePool(4);

	UE_LOG(LogNebulaDatabase, Warning, TEXT("NebulaDatabase: StartupModule end"));
}

void FNebulaDatabaseModule::ShutdownModule()
{
	FNebulaDbConsoleCommands::Unregister();
	
	ShutdownPool();
	

	if (GMariaDbHandle)
	{
		FPlatformProcess::FreeDllHandle(GMariaDbHandle);
		GMariaDbHandle = nullptr;
	}

	Pool.Reset();
}

FNebulaDbPool& FNebulaDatabaseModule::GetPool()
{
	check(Pool.IsValid());
	return *Pool.Get();
}

bool FNebulaDatabaseModule::InitializePool(int32 PoolSize)
{
	if (!Pool.IsValid())
	{
		Pool = MakeUnique<FNebulaDbPool>();
	}

	if (bPoolInitialized)
	{
		return true;
	}

	const auto Creds = NebulaDatabaseSettingsHelpers::GetCredentials();

	const bool bOk = Pool->Initialize(Creds, PoolSize);
	bPoolInitialized = bOk;

	if (!bOk)
	{
		UE_LOG(LogNebulaDatabase, Error, TEXT("NebulaDatabase: Pool initialization failed."));
	}
	else
	{
		UE_LOG(LogNebulaDatabase, Warning, TEXT("NebulaDatabase: Pool initialized (size=%d)."), PoolSize);
	}

	return bOk;
}

void FNebulaDatabaseModule::ShutdownPool()
{
	if (Pool.IsValid() && bPoolInitialized)
	{
		Pool->Shutdown();
		bPoolInitialized = false;
	}
}

IMPLEMENT_MODULE(FNebulaDatabaseModule, NebulaDatabase)