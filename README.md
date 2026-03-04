# NebulaDatabase

Unreal Engine plugin providing MariaDB/MySQL connectivity using MariaDB Connector/C.

## Features

- MariaDB Connector/C integration
- Async query execution
- Connection pooling
- Config-driven credentials
- Unreal console debugging commands
- Plugin-safe DLL loading

## Console Commands

NebulaDB.SmokeTest  
NebulaDB.Select <SQL>  
NebulaDB.Update <SQL>

## Configuration

Create:

Config/DefaultNebulaDatabase.ini

[/Script/NebulaDatabase.NebulaDatabaseSettings]
DatabaseHost=127.0.0.1
DatabaseUser=root
DatabasePassword=
DatabaseName=mysql
DatabasePort=3306
DatabaseConnectTimeoutSeconds=5
