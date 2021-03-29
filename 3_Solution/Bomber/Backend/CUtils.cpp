#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "CUtils.h"
#include "CMiscException.h"
#include "Config.h"

#pragma region Database

MYSQL* CUtils::ConnectToDatabase()
{
	MYSQL* conn;

	conn = mysql_init(0);
	conn = mysql_real_connect(conn, DATABASE_HOST, DATABASE_USER, DATABASE_PASSWORD, DATABASE_DEFAULT_DB, DATABASE_PORT, NULL, 0);
	if (conn)
	{
		return conn;
	}
	else
	{
		throw CMiscException(ERROR_CANNOT_CONNECT_TO_DATABASE);
	}
}

MYSQL_RES* CUtils::QueryDatabase(MYSQL* _connection, std::string _query)
{
	MYSQL_RES* res;
	MYSQL_ROW row;
	int _qstate;

	_qstate = mysql_query(_connection, _query.c_str());
	if (!_qstate)
	{
		res = mysql_store_result(_connection);
		return res;
	}
	else
	{
		printf(mysql_error(_connection));
		throw CMiscException(ERROR_IN_QUERYING_DATABASE);
	}
}

void CUtils::CloseConnectionToDatabase(MYSQL* connection) {

	mysql_close(connection);
}

#pragma endregion

#pragma region Misc

std::string CUtils::GetSerialization(std::list<std::string> _stringList, char delimiter)
{
	std::string returned;

	for (auto const& it : _stringList)
	{
		returned += it + delimiter;
	}
	return returned;
}

std::string CUtils::GetFormattedTime(time_t _specifiedTime)
{
	char buffer[LOGGER_MAX_DATE_STRING];
	time_t now;
	tm* lt;

	if (time == 0)
		now = time(0);
	else
		now = _specifiedTime;
	lt = localtime(&now);
	strftime(buffer, LOGGER_MAX_DATE_STRING, "%d %d %Y %H:%M:%S", lt);
	return std::string(buffer);
}

#pragma endregion
