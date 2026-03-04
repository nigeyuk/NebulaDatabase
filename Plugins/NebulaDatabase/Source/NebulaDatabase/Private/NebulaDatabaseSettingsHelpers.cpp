// Copyright 2026 U4RIA Studios

#include "NebulaDatabaseSettingsHelpers.h"
#include "NebulaDatabaseSettings.h"

FNebulaDatabaseCredentials NebulaDatabaseSettingsHelpers::GetCredentials()
{
	const UNebulaDatabaseSettings* S  = GetDefault<UNebulaDatabaseSettings>();
	
	FNebulaDatabaseCredentials Out;
	Out.Host = S->DatabaseHost;
	Out.User = S->DatabaseUser;
	Out.Password = S->DatabasePassword;
	Out.Database = S->DatabaseName;
	Out.Port = S->DatabasePort;
	Out.ConnectTimeoutSeconds = S->DatabaseConnectTimeoutSeconds;
	return Out;
}
