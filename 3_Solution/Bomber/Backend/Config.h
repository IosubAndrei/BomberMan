#pragma once

// Path of solution
#define PATH_PROJECT											"C:\\Users\\IOSUB\\Desktop\\PROIECT\\BomberMan\\3_Solution\\Bomber\\"

// Path of projects
#define PATH_BACKEND											PATH_PROJECT "Backend\\"
#define PATH_SERVER												PATH_PROJECT "Server\\"
#define PATH_CLIENT												PATH_PROJECT "Client\\"

// Logger
#define LOGGER_DEFAULT_FILE										"default.log"
#define LOGGER_MODE_APPEND										"a"
#define LOGGER_MODE_WRITE										"w"
#define LOGGER_MODE_READ										"r"
#define LOGGER_MODE_BINARY_WRITE								"wb"
#define LOGGER_MODE_BINARY_READ									"rb"
#define LOGGER_MAX_DATE_STRING									64

//	Protocol
#define PROTOCOL_DELIMITATOR									'\1'

//	Packet
#define PACKET_MAX_SIZE											8192

//	Winsock
#define WINSOCK_RECOMMANDED_CHUNK_SIZE							1000

//Databases
#define DATABASE_HOST											""
#define DATABASE_DEFAULT_DB										""
#define DATABASE_USER											""
#define DATABASE_PASSWORD										""
#define DATABASE_PORT											3306
#define DATABASE_TABLE_USERS									"Users"
#define DATABASE_TABLE_REQUESTS									"Requests"
#define DATABASE_QUERY_IMPORT									"SELECT * FROM "
#define DATABASE_QUERY_TRUNCATE									"TRUNCATE TABLE "
#define DATABASE_QUERY_INSERT_HEADING							"INSERT INTO "
#define DATABASE_QUERY_INSERT_LEADING							" VALUES "
#define DATABASE_QUERY_INSERT_DELIMITATOR						", "

// User Details
#define USER_DETAILS_BUFFER_SIZE								128
#define USER_DETAILS_BUFFER_FORMAT								"%d, %d, %d, %s"

// SQL serialization for object
#define SQL_SERIALIZE_BUFFER_SIZE								256
#define SQL_SERIALIZE_USER_BUFFER_FORMAT						"(%d, '%s', '%s', '%s', %d, %d)"
#define SQL_SERIALIZE_DEMAND_BUFFER_FORMAT						"(%d, '%s', '%s')"
#define SQL_SERIALIZE_REQUEST_BUFFER_FORMAT						"(%d, %lli, '%s', '%s', %d, %d, %d, %d)"