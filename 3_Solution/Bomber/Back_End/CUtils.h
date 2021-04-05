#pragma once
#include <string>
#include <list>
#include <time.h>
#include <mysql.h>

class CUtils
{
public:

	//Database-oriented methods
	static MYSQL* ConnectToDatabase();
	static MYSQL_RES* QueryDatabase(MYSQL* _connection, std::string _query);
	static void CloseConnectionToDatabase(MYSQL* _connection);

	static std::string GetSerialization(std::list<std::string> _stringList, char _delimiter);
	static std::string GetFormattedTime(time_t _specifiedTime = 0);

};

