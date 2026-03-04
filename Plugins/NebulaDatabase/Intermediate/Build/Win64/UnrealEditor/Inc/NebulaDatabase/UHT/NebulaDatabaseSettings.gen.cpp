// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NebulaDatabaseSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeNebulaDatabaseSettings() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
NEBULADATABASE_API UClass* Z_Construct_UClass_UNebulaDatabaseSettings();
NEBULADATABASE_API UClass* Z_Construct_UClass_UNebulaDatabaseSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_NebulaDatabase();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UNebulaDatabaseSettings **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UNebulaDatabaseSettings;
UClass* UNebulaDatabaseSettings::GetPrivateStaticClass()
{
	using TClass = UNebulaDatabaseSettings;
	if (!Z_Registration_Info_UClass_UNebulaDatabaseSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("NebulaDatabaseSettings"),
			Z_Registration_Info_UClass_UNebulaDatabaseSettings.InnerSingleton,
			StaticRegisterNativesUNebulaDatabaseSettings,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UNebulaDatabaseSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UNebulaDatabaseSettings_NoRegister()
{
	return UNebulaDatabaseSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UNebulaDatabaseSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Config-backed settings for NebulaDatabase.\n *\n * Loaded from:\n *   Config/DefaultNebulaDatabase.ini  (defaults)\n *   Saved/Config/<Platform>/NebulaDatabase.ini (user overrides)\n *\n * Section:\n *   [NebulaDatabase.DatabaseCredentials]\n */" },
#endif
		{ "IncludePath", "NebulaDatabaseSettings.h" },
		{ "ModuleRelativePath", "Public/NebulaDatabaseSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Config-backed settings for NebulaDatabase.\n\nLoaded from:\n  Config/DefaultNebulaDatabase.ini  (defaults)\n  Saved/Config/<Platform>/NebulaDatabase.ini (user overrides)\n\nSection:\n  [NebulaDatabase.DatabaseCredentials]" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DatabaseHost_MetaData[] = {
		{ "Category", "DatabaseCredentials" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Hostname or IP\n" },
#endif
		{ "ModuleRelativePath", "Public/NebulaDatabaseSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hostname or IP" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DatabaseUser_MetaData[] = {
		{ "Category", "DatabaseCredentials" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Username\n" },
#endif
		{ "ModuleRelativePath", "Public/NebulaDatabaseSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Username" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DatabasePassword_MetaData[] = {
		{ "Category", "DatabaseCredentials" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Password\n" },
#endif
		{ "ModuleRelativePath", "Public/NebulaDatabaseSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Password" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DatabaseName_MetaData[] = {
		{ "Category", "DatabaseCredentials" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Default database / schema name\n" },
#endif
		{ "ModuleRelativePath", "Public/NebulaDatabaseSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default database / schema name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DatabasePort_MetaData[] = {
		{ "Category", "DatabaseCredentials" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Tcp Port (Generally the default port (3306))\n" },
#endif
		{ "ModuleRelativePath", "Public/NebulaDatabaseSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tcp Port (Generally the default port (3306))" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DatabaseConnectTimeoutSeconds_MetaData[] = {
		{ "Category", "DatabaseCredentials" },
		{ "ClampMax", "120" },
		{ "ClampMin", "1" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Connection timeout (seconds).  Keep this small for server startup reliability.\n" },
#endif
		{ "ModuleRelativePath", "Public/NebulaDatabaseSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Connection timeout (seconds).  Keep this small for server startup reliability." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UNebulaDatabaseSettings constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_DatabaseHost;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DatabaseUser;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DatabasePassword;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DatabaseName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DatabasePort;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DatabaseConnectTimeoutSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UNebulaDatabaseSettings constinit property declarations ********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNebulaDatabaseSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UNebulaDatabaseSettings_Statics

// ********** Begin Class UNebulaDatabaseSettings Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UNebulaDatabaseSettings_Statics::NewProp_DatabaseHost = { "DatabaseHost", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNebulaDatabaseSettings, DatabaseHost), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DatabaseHost_MetaData), NewProp_DatabaseHost_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UNebulaDatabaseSettings_Statics::NewProp_DatabaseUser = { "DatabaseUser", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNebulaDatabaseSettings, DatabaseUser), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DatabaseUser_MetaData), NewProp_DatabaseUser_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UNebulaDatabaseSettings_Statics::NewProp_DatabasePassword = { "DatabasePassword", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNebulaDatabaseSettings, DatabasePassword), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DatabasePassword_MetaData), NewProp_DatabasePassword_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UNebulaDatabaseSettings_Statics::NewProp_DatabaseName = { "DatabaseName", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNebulaDatabaseSettings, DatabaseName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DatabaseName_MetaData), NewProp_DatabaseName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UNebulaDatabaseSettings_Statics::NewProp_DatabasePort = { "DatabasePort", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNebulaDatabaseSettings, DatabasePort), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DatabasePort_MetaData), NewProp_DatabasePort_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UNebulaDatabaseSettings_Statics::NewProp_DatabaseConnectTimeoutSeconds = { "DatabaseConnectTimeoutSeconds", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNebulaDatabaseSettings, DatabaseConnectTimeoutSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DatabaseConnectTimeoutSeconds_MetaData), NewProp_DatabaseConnectTimeoutSeconds_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UNebulaDatabaseSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNebulaDatabaseSettings_Statics::NewProp_DatabaseHost,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNebulaDatabaseSettings_Statics::NewProp_DatabaseUser,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNebulaDatabaseSettings_Statics::NewProp_DatabasePassword,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNebulaDatabaseSettings_Statics::NewProp_DatabaseName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNebulaDatabaseSettings_Statics::NewProp_DatabasePort,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNebulaDatabaseSettings_Statics::NewProp_DatabaseConnectTimeoutSeconds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNebulaDatabaseSettings_Statics::PropPointers) < 2048);
// ********** End Class UNebulaDatabaseSettings Property Definitions *******************************
UObject* (*const Z_Construct_UClass_UNebulaDatabaseSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_NebulaDatabase,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNebulaDatabaseSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UNebulaDatabaseSettings_Statics::ClassParams = {
	&UNebulaDatabaseSettings::StaticClass,
	"NebulaDatabase",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UNebulaDatabaseSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UNebulaDatabaseSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNebulaDatabaseSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UNebulaDatabaseSettings_Statics::Class_MetaDataParams)
};
void UNebulaDatabaseSettings::StaticRegisterNativesUNebulaDatabaseSettings()
{
}
UClass* Z_Construct_UClass_UNebulaDatabaseSettings()
{
	if (!Z_Registration_Info_UClass_UNebulaDatabaseSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNebulaDatabaseSettings.OuterSingleton, Z_Construct_UClass_UNebulaDatabaseSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UNebulaDatabaseSettings.OuterSingleton;
}
UNebulaDatabaseSettings::UNebulaDatabaseSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UNebulaDatabaseSettings);
UNebulaDatabaseSettings::~UNebulaDatabaseSettings() {}
// ********** End Class UNebulaDatabaseSettings ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseSettings_h__Script_NebulaDatabase_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UNebulaDatabaseSettings, UNebulaDatabaseSettings::StaticClass, TEXT("UNebulaDatabaseSettings"), &Z_Registration_Info_UClass_UNebulaDatabaseSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNebulaDatabaseSettings), 3636044833U) },
	};
}; // Z_CompiledInDeferFile_FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseSettings_h__Script_NebulaDatabase_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseSettings_h__Script_NebulaDatabase_3752024805{
	TEXT("/Script/NebulaDatabase"),
	Z_CompiledInDeferFile_FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseSettings_h__Script_NebulaDatabase_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseSettings_h__Script_NebulaDatabase_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
