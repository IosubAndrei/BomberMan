#pragma once

//Misc error codes
#pragma region MiscErrorCodes
#define ERROR_BASE							100
#define ERROR_UNKNOWN_ERROR_CODE			ERROR_BASE+1
#define ERROR_LOGGER_CANT_OPEN_FILE								ERROR_BASE + 2
#define ERROR_LOGGING_FILE_NOT_SET								ERROR_BASE + 3
#define ERROR_UNKNOWN_LOGGING_TYPE								ERROR_BASE + 4
#define ERROR_CANNOT_CONNECT_TO_DATABASE						ERROR_BASE + 5
#pragma endregion

//Server app error codes
#pragma region ServerErrorCodes
#define ERROR_SERVER_BASE										200
#define ERROR_SERVER_UNKNOWN_ERROR_CODE							ERROR_SERVER_BASE + 1
#define ERROR_SERVER_INSTANCE_IS_CREATED						ERROR_SERVER_BASE + 2
#define ERROR_SERVER_INSTANCE_DOESNT_EXIST						ERROR_SERVER_BASE + 3
#define ERROR_SERVER_USERNAME_NOT_AVAILABLE						ERROR_SERVER_BASE + 4
#define ERROR_SERVER_USER_NOT_FOUND								ERROR_SERVER_BASE + 5
#define ERROR_SERVER_IS_ALREADY_ON								ERROR_SERVER_BASE + 6
#define ERROR_SERVER_IS_ALREADY_OFF								ERROR_SERVER_BASE + 7
#define ERROR_LOGGER_CANT_OPEN_FILE								ERROR_SERVER_BASE + 8

#pragma endregion

// Client app error codes
#pragma region ClientErrorCodes
#define ERROR_CLIENT_BASE										300
#define ERROR_CLIENT_UNKNOWN_ERROR_CODE							ERROR_CLIENT_BASE + 1
#define ERROR_CLIENT_INSTANCE_IS_CREATED						ERROR_CLIENT_BASE + 2
#define ERROR_CLIENT_INSTANCE_DOESNT_EXIST						ERROR_CLIENT_BASE + 3
#define ERROR_CLIENT_NO_USER_IS_LOGGED							ERROR_CLIENT_BASE + 4
#define ERROR_CLIENT_NO_ADMINISTRATOR_PRIVILEGES				ERROR_CLIENT_BASE + 5
#pragma endregion
