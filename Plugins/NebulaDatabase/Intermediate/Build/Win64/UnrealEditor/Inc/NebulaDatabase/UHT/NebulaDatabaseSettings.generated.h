// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "NebulaDatabaseSettings.h"

#ifdef NEBULADATABASE_NebulaDatabaseSettings_generated_h
#error "NebulaDatabaseSettings.generated.h already included, missing '#pragma once' in NebulaDatabaseSettings.h"
#endif
#define NEBULADATABASE_NebulaDatabaseSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UNebulaDatabaseSettings **************************************************
struct Z_Construct_UClass_UNebulaDatabaseSettings_Statics;
NEBULADATABASE_API UClass* Z_Construct_UClass_UNebulaDatabaseSettings_NoRegister();

#define FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseSettings_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUNebulaDatabaseSettings(); \
	friend struct ::Z_Construct_UClass_UNebulaDatabaseSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend NEBULADATABASE_API UClass* ::Z_Construct_UClass_UNebulaDatabaseSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UNebulaDatabaseSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/NebulaDatabase"), Z_Construct_UClass_UNebulaDatabaseSettings_NoRegister) \
	DECLARE_SERIALIZER(UNebulaDatabaseSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("NebulaDatabase");} \



#define FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseSettings_h_22_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UNebulaDatabaseSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UNebulaDatabaseSettings(UNebulaDatabaseSettings&&) = delete; \
	UNebulaDatabaseSettings(const UNebulaDatabaseSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNebulaDatabaseSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNebulaDatabaseSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNebulaDatabaseSettings) \
	NO_API virtual ~UNebulaDatabaseSettings();


#define FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseSettings_h_19_PROLOG
#define FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseSettings_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseSettings_h_22_INCLASS_NO_PURE_DECLS \
	FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseSettings_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UNebulaDatabaseSettings;

// ********** End Class UNebulaDatabaseSettings ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_NebulaSQL_Plugins_NebulaDatabase_Source_NebulaDatabase_Public_NebulaDatabaseSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
