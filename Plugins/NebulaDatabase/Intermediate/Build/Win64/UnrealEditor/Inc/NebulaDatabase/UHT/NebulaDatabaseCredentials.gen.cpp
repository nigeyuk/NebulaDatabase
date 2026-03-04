// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NebulaDatabaseCredentials.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeNebulaDatabaseCredentials() {}

// ********** Begin Cross Module References ********************************************************
NEBULADATABASE_API UScriptStruct* Z_Construct_UScriptStruct_FNebulaDatabaseCredentials();
UPackage* Z_Construct_UPackage__Script_NebulaDatabase();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FNebulaDatabaseCredentials ****************************************
struct Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FNebulaDatabaseCredentials); }
	static inline consteval int16 GetStructAlignment() { return alignof(FNebulaDatabaseCredentials); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/NebulaDatabaseCredentials.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Host_MetaData[] = {
		{ "Category", "DatabaseCredentials" },
		{ "ModuleRelativePath", "Public/NebulaDatabaseCredentials.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_User_MetaData[] = {
		{ "Category", "DatabaseCredentials" },
		{ "ModuleRelativePath", "Public/NebulaDatabaseCredentials.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Password_MetaData[] = {
		{ "Category", "DatabaseCredentials" },
		{ "ModuleRelativePath", "Public/NebulaDatabaseCredentials.h" },
		{ "PasswordField", "TRUE" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Database_MetaData[] = {
		{ "Category", "DatabaseCredentials" },
		{ "ModuleRelativePath", "Public/NebulaDatabaseCredentials.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Port_MetaData[] = {
		{ "Category", "DatabaseCredentials" },
		{ "ModuleRelativePath", "Public/NebulaDatabaseCredentials.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConnectTimeoutSeconds_MetaData[] = {
		{ "Category", "DatabaseCredentials" },
		{ "ClampMax", "120" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/NebulaDatabaseCredentials.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FNebulaDatabaseCredentials constinit property declarations ********
	static const UECodeGen_Private::FStrPropertyParams NewProp_Host;
	static const UECodeGen_Private::FStrPropertyParams NewProp_User;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Password;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Database;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Port;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ConnectTimeoutSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FNebulaDatabaseCredentials constinit property declarations **********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNebulaDatabaseCredentials>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FNebulaDatabaseCredentials;
class UScriptStruct* FNebulaDatabaseCredentials::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FNebulaDatabaseCredentials.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FNebulaDatabaseCredentials.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FNebulaDatabaseCredentials, (UObject*)Z_Construct_UPackage__Script_NebulaDatabase(), TEXT("NebulaDatabaseCredentials"));
	}
	return Z_Registration_Info_UScriptStruct_FNebulaDatabaseCredentials.OuterSingleton;
	}

// ********** Begin ScriptStruct FNebulaDatabaseCredentials Property Definitions *******************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::NewProp_Host = { "Host", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNebulaDatabaseCredentials, Host), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Host_MetaData), NewProp_Host_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::NewProp_User = { "User", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNebulaDatabaseCredentials, User), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_User_MetaData), NewProp_User_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::NewProp_Password = { "Password", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNebulaDatabaseCredentials, Password), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Password_MetaData), NewProp_Password_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::NewProp_Database = { "Database", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNebulaDatabaseCredentials, Database), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Database_MetaData), NewProp_Database_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::NewProp_Port = { "Port", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNebulaDatabaseCredentials, Port), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Port_MetaData), NewProp_Port_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::NewProp_ConnectTimeoutSeconds = { "ConnectTimeoutSeconds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNebulaDatabaseCredentials, ConnectTimeoutSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConnectTimeoutSeconds_MetaData), NewProp_ConnectTimeoutSeconds_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::NewProp_Host,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::NewProp_User,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::NewProp_Password,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::NewProp_Database,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::NewProp_Port,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::NewProp_ConnectTimeoutSeconds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FNebulaDatabaseCredentials Property Definitions *********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_NebulaDatabase,
	nullptr,
	&NewStructOps,
	"NebulaDatabaseCredentials",
	Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::PropPointers),
	sizeof(FNebulaDatabaseCredentials),
	alignof(FNebulaDatabaseCredentials),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FNebulaDatabaseCredentials()
{
	if (!Z_Registration_Info_UScriptStruct_FNebulaDatabaseCredentials.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FNebulaDatabaseCredentials.InnerSingleton, Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FNebulaDatabaseCredentials.InnerSingleton);
}
// ********** End ScriptStruct FNebulaDatabaseCredentials ******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseCredentials_h__Script_NebulaDatabase_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FNebulaDatabaseCredentials::StaticStruct, Z_Construct_UScriptStruct_FNebulaDatabaseCredentials_Statics::NewStructOps, TEXT("NebulaDatabaseCredentials"),&Z_Registration_Info_UScriptStruct_FNebulaDatabaseCredentials, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FNebulaDatabaseCredentials), 3805030680U) },
	};
}; // Z_CompiledInDeferFile_FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseCredentials_h__Script_NebulaDatabase_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseCredentials_h__Script_NebulaDatabase_1686489284{
	TEXT("/Script/NebulaDatabase"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseCredentials_h__Script_NebulaDatabase_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseCredentials_h__Script_NebulaDatabase_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
