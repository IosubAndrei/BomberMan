#pragma once
#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <stdio.h>

#include <odbcss.h>

#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000

#define TEXTSIZE 12000
#define MAXBUFLEN 256

#define SUPRESS_SQL_MANAGER 1

using namespace std;

enum class QueryDelimiter
{
	Space,
	NewLine,
	Null,
	DollarSign
};

class Query
{
private:
	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	SQLHANDLE sqlEnvHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];

	void terminateQuery();
	void initDelimiter(char& delimiter, QueryDelimiter);

public:

	Query();

	string getAllUserNames();
	string makeCustomQuery(const wchar_t* query, int column, QueryDelimiter query_delimiter = QueryDelimiter::Space); // ex: "SELECT * FROM Employees"
	string makeRangedQuery(const wchar_t* query, int column_start, int column_finish, QueryDelimiter query_delimiter = QueryDelimiter::Space);

	void insertData(wstring);

	~Query();
};

