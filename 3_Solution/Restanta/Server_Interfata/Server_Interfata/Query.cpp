#include "Query.h"

Query::Query()
{

	//Initialization
	sqlConnHandle = NULL;
	sqlStmtHandle = NULL;

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))
	{
		this->terminateQuery();
		return;
	}
	if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
	{
		this->terminateQuery();
		return;
	}
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))
	{
		this->terminateQuery();
		return;
	}

	//Output
	if (!SUPRESS_SQL_MANAGER)
	{
		cout << "Attempting connection to SQL Server...";
		cout << "\n";
	}

	//Connect to SQL Server

	switch (SQLDriverConnect(sqlConnHandle,
		NULL,
		(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=Bomber;Trusted=true;",
		SQL_NTS,
		retconstring,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT)) {
	case SQL_SUCCESS:
		if (!SUPRESS_SQL_MANAGER)
		{
			cout << "Successfully connected to SQL Server";
			cout << "\n";
		}
		break;

	case SQL_SUCCESS_WITH_INFO:
		if (!SUPRESS_SQL_MANAGER) {
			cout << "Successfully connected to SQL Server";
			cout << "\n";
		}
		break;
	case SQL_INVALID_HANDLE:
		if (!SUPRESS_SQL_MANAGER) {
			cout << "Could not connect to SQL Server due to invalid handler";
			cout << "\n";
		}
		this->terminateQuery();
		return;

	case SQL_ERROR:
		if (!SUPRESS_SQL_MANAGER) {
			cout << "Could not connect to SQL Server due to SQL error";
			cout << "\n";
		}
		this->terminateQuery();
		return;

	default:
		break;
	}

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
	{
		this->terminateQuery();
	}
	return;

	//Output
	if (!SUPRESS_SQL_MANAGER) {
		cout << "\n";
		cout << "Executing T-SQL query...";
		cout << "\n";
	}

}

string Query::getAllUserNames()
{
	return makeCustomQuery(L"SELECT FirstName + ' ' + LastName FROM Users", 1, QueryDelimiter::NewLine);
}

string Query::makeRangedQuery(const wchar_t* query, int column_start, int column_finish, QueryDelimiter query_delimiter)
{
	char delimiter;
	initDelimiter(delimiter, query_delimiter);

	wstring ws;
	string return_buffer;
	ws += query;

	//If there is a problem executing then exit application
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)ws.c_str(), SQL_NTS))
	{
		cout << "Error querying SQL Server";
		cout << "\n";
		return NULL;
	}
	else
	{
		//declare output variable and pointer
		SQLCHAR sqlVersion[SQL_RESULT_LEN];

		SQLINTEGER ptrSqlVersion;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
		{
			//template pentru ciclarea mai multor coloane
			for (int index = column_start; index < column_finish; index++)
			{
				SQLGetData(sqlStmtHandle, index, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, (SQLLEN*)&ptrSqlVersion);
				return_buffer += (string((const char*)sqlVersion)) + delimiter;
			}
		}
	}
	return return_buffer;
}

string Query::makeCustomQuery(const wchar_t* query, int column, QueryDelimiter query_delimiter)
{
	char delimiter;
	initDelimiter(delimiter, query_delimiter);

	wstring ws;
	string return_buffer;
	ws += query;

	//If there is a problem executing then exit application
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)ws.c_str(), SQL_NTS))
	{
		cout << "Error querying SQL Server";
		cout << "\n";
		return NULL;
	}
	else
	{
		//declare output variable and pointer
		SQLCHAR sqlVersion[SQL_RESULT_LEN];

		SQLINTEGER ptrSqlVersion;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
		{
			SQLGetData(sqlStmtHandle, column, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, (SQLLEN*)&ptrSqlVersion);
			return_buffer += (string((const char*)sqlVersion)) + delimiter;
		}
	}

	return return_buffer;
}

void Query::insertData(wstring queryBuffer)
{
	SQLExecDirect(sqlStmtHandle,
		(SQLWCHAR*)queryBuffer.c_str(),
		SQL_NTS);
}

void Query::terminateQuery()
{
	//close connection and free resources
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
}

void Query::initDelimiter(char& delimiter, QueryDelimiter queryDelimiter)
{
	switch (queryDelimiter) {
	case (QueryDelimiter::NewLine): {
		delimiter = '\n';
		break;
	}
	case (QueryDelimiter::Space): {
		delimiter = ' ';
		break;
	}
	case (QueryDelimiter::Null): {
		delimiter = 0;
		break;
	}
	case (QueryDelimiter::DollarSign): {
		delimiter = '$';
		break;
	}
	default:
	{
		delimiter = ' ';
	}
	}
}

Query::~Query()
{
	//close connection and free resources
	this->terminateQuery();
}

