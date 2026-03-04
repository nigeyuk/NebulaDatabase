// Copyright 2026 U4RIA Studios

using UnrealBuildTool;
using System.IO;

public class NebulaDatabase : ModuleRules
{
	public NebulaDatabase(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"CoreUObject",
			"Engine",
			"Projects"
		});

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			string ThirdParty = Path.Combine(ModuleDirectory, "..", "ThirdParty", "MariaDB");
			string IncludePath = Path.Combine(ThirdParty, "Include");
			string LibPath = Path.Combine(ThirdParty, "Lib");

			PublicSystemIncludePaths.Add(IncludePath);

			PublicAdditionalLibraries.Add(Path.Combine(LibPath, "mariadbclient.lib"));

			PublicDelayLoadDLLs.Add("libmariadb.dll");
			RuntimeDependencies.Add("$(PluginDir)/Binaries/Win64/libmariadb.dll");

			// Required by MariaDB Connector/C when built with Windows TLS (SChannel) + CNG
			PublicSystemLibraries.AddRange(new string[]
			{
				"secur32.lib",
				"crypt32.lib",
				"bcrypt.lib",
				"shlwapi.lib"
			});
		}
	}
}