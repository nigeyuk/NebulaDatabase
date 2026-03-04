// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NebulaDatabaseQueryResult.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeNebulaDatabaseQueryResult() {}

// ********** Begin Cross Module References ********************************************************
NEBULADATABASE_API UScriptStruct* Z_Construct_UScriptStruct_FNebulaQueryResult();
NEBULADATABASE_API UScriptStruct* Z_Construct_UScriptStruct_FNebulaQueryRow();
UPackage* Z_Construct_UPackage__Script_NebulaDatabase();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FNebulaQueryRow ***************************************************
struct Z_Construct_UScriptStruct_FNebulaQueryRow_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FNebulaQueryRow); }
	static inline consteval int16 GetStructAlignment() { return alignof(FNebulaQueryRow); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/NebulaDatabaseQueryResult.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Cells_MetaData[] = {
		{ "Category", "Database" },
		{ "ModuleRelativePath", "Public/NebulaDatabaseQueryResult.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FNebulaQueryRow constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Cells_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Cells;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FNebulaQueryRow constinit property declarations *********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNebulaQueryRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FNebulaQueryRow_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FNebulaQueryRow;
class UScriptStruct* FNebulaQueryRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FNebulaQueryRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FNebulaQueryRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FNebulaQueryRow, (UObject*)Z_Construct_UPackage__Script_NebulaDatabase(), TEXT("NebulaQueryRow"));
	}
	return Z_Registration_Info_UScriptStruct_FNebulaQueryRow.OuterSingleton;
	}

// ********** Begin ScriptStruct FNebulaQueryRow Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FNebulaQueryRow_Statics::NewProp_Cells_Inner = { "Cells", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FNebulaQueryRow_Statics::NewProp_Cells = { "Cells", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNebulaQueryRow, Cells), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Cells_MetaData), NewProp_Cells_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FNebulaQueryRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNebulaQueryRow_Statics::NewProp_Cells_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNebulaQueryRow_Statics::NewProp_Cells,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNebulaQueryRow_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FNebulaQueryRow Property Definitions ********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FNebulaQueryRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_NebulaDatabase,
	nullptr,
	&NewStructOps,
	"NebulaQueryRow",
	Z_Construct_UScriptStruct_FNebulaQueryRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNebulaQueryRow_Statics::PropPointers),
	sizeof(FNebulaQueryRow),
	alignof(FNebulaQueryRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNebulaQueryRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FNebulaQueryRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FNebulaQueryRow()
{
	if (!Z_Registration_Info_UScriptStruct_FNebulaQueryRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FNebulaQueryRow.InnerSingleton, Z_Construct_UScriptStruct_FNebulaQueryRow_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FNebulaQueryRow.InnerSingleton);
}
// ********** End ScriptStruct FNebulaQueryRow *****************************************************

// ********** Begin ScriptStruct FNebulaQueryResult ************************************************
struct Z_Construct_UScriptStruct_FNebulaQueryResult_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FNebulaQueryResult); }
	static inline consteval int16 GetStructAlignment() { return alignof(FNebulaQueryResult); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/NebulaDatabaseQueryResult.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSuccess_MetaData[] = {
		{ "Category", "Database" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** True if the query executed successfully */" },
#endif
		{ "ModuleRelativePath", "Public/NebulaDatabaseQueryResult.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "True if the query executed successfully" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorCode_MetaData[] = {
		{ "Category", "Database" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** MariaDB/MySQL error code */" },
#endif
		{ "ModuleRelativePath", "Public/NebulaDatabaseQueryResult.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "MariaDB/MySQL error code" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "Category", "Database" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Error message */" },
#endif
		{ "ModuleRelativePath", "Public/NebulaDatabaseQueryResult.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Error message" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AffectedRows_MetaData[] = {
		{ "Category", "Database" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Affected rows (UPDATE/INSERT/DELETE) */" },
#endif
		{ "ModuleRelativePath", "Public/NebulaDatabaseQueryResult.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Affected rows (UPDATE/INSERT/DELETE)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Columns_MetaData[] = {
		{ "Category", "Database" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Column names */" },
#endif
		{ "ModuleRelativePath", "Public/NebulaDatabaseQueryResult.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Column names" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rows_MetaData[] = {
		{ "Category", "Database" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Result rows */" },
#endif
		{ "ModuleRelativePath", "Public/NebulaDatabaseQueryResult.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Result rows" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FNebulaQueryResult constinit property declarations ****************
	static void NewProp_bSuccess_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ErrorCode;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_AffectedRows;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Columns_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Columns;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rows_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Rows;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FNebulaQueryResult constinit property declarations ******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNebulaQueryResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FNebulaQueryResult_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FNebulaQueryResult;
class UScriptStruct* FNebulaQueryResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FNebulaQueryResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FNebulaQueryResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FNebulaQueryResult, (UObject*)Z_Construct_UPackage__Script_NebulaDatabase(), TEXT("NebulaQueryResult"));
	}
	return Z_Registration_Info_UScriptStruct_FNebulaQueryResult.OuterSingleton;
	}

// ********** Begin ScriptStruct FNebulaQueryResult Property Definitions ***************************
void Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::NewProp_bSuccess_SetBit(void* Obj)
{
	((FNebulaQueryResult*)Obj)->bSuccess = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FNebulaQueryResult), &Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSuccess_MetaData), NewProp_bSuccess_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::NewProp_ErrorCode = { "ErrorCode", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNebulaQueryResult, ErrorCode), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorCode_MetaData), NewProp_ErrorCode_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNebulaQueryResult, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::NewProp_AffectedRows = { "AffectedRows", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNebulaQueryResult, AffectedRows), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AffectedRows_MetaData), NewProp_AffectedRows_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::NewProp_Columns_Inner = { "Columns", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::NewProp_Columns = { "Columns", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNebulaQueryResult, Columns), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Columns_MetaData), NewProp_Columns_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::NewProp_Rows_Inner = { "Rows", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FNebulaQueryRow, METADATA_PARAMS(0, nullptr) }; // 3645130850
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::NewProp_Rows = { "Rows", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FNebulaQueryResult, Rows), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rows_MetaData), NewProp_Rows_MetaData) }; // 3645130850
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::NewProp_ErrorCode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::NewProp_ErrorMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::NewProp_AffectedRows,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::NewProp_Columns_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::NewProp_Columns,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::NewProp_Rows_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::NewProp_Rows,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FNebulaQueryResult Property Definitions *****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_NebulaDatabase,
	nullptr,
	&NewStructOps,
	"NebulaQueryResult",
	Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::PropPointers),
	sizeof(FNebulaQueryResult),
	alignof(FNebulaQueryResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FNebulaQueryResult()
{
	if (!Z_Registration_Info_UScriptStruct_FNebulaQueryResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FNebulaQueryResult.InnerSingleton, Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FNebulaQueryResult.InnerSingleton);
}
// ********** End ScriptStruct FNebulaQueryResult **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseQueryResult_h__Script_NebulaDatabase_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FNebulaQueryRow::StaticStruct, Z_Construct_UScriptStruct_FNebulaQueryRow_Statics::NewStructOps, TEXT("NebulaQueryRow"),&Z_Registration_Info_UScriptStruct_FNebulaQueryRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FNebulaQueryRow), 3645130850U) },
		{ FNebulaQueryResult::StaticStruct, Z_Construct_UScriptStruct_FNebulaQueryResult_Statics::NewStructOps, TEXT("NebulaQueryResult"),&Z_Registration_Info_UScriptStruct_FNebulaQueryResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FNebulaQueryResult), 1240833287U) },
	};
}; // Z_CompiledInDeferFile_FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseQueryResult_h__Script_NebulaDatabase_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseQueryResult_h__Script_NebulaDatabase_3179247530{
	TEXT("/Script/NebulaDatabase"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseQueryResult_h__Script_NebulaDatabase_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseQueryResult_h__Script_NebulaDatabase_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
