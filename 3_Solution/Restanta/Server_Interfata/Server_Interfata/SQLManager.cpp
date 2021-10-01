#include "SQLManager.h"

SQLManager* SQLManager::instance = nullptr;

SQLManager::SQLManager()
{
	cout << "SQL Manager up and running." << endl;
}

SQLManager* SQLManager::getInstance()
{
    if (instance == nullptr)
        instance = new SQLManager;
    return instance;
}

string SQLManager::makeCustomQuery(const wchar_t* query, int column)
{
    Query* temp_query = new Query;

    return temp_query->makeCustomQuery(query, column);
}

void SQLManager::destroyInstance()
{
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}

string SQLManager::getAllUserNames()
{
    Query* temp_query = new Query;

    return temp_query->getAllUserNames();
}

int SQLManager::getUserRole(string _firstName)
{
    Query* temp_query = new Query;
    string query;

    query = "select UserRole from Users where FirstName = '" + _firstName + "'";
    return atoi(temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1).c_str());
}

int SQLManager::getUserID(string _firstName)
{
    Query* temp_query = new Query;
    string query;

    query = "select UserID from Users where FirstName = '" + _firstName + "'";
    string returnBuffer = temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1);
    return stoi(returnBuffer);
}

string SQLManager::makeRangedQuery(const wchar_t* query, int column_start, int column_finish)
{
    Query* temp_query = new Query;
    return temp_query->makeRangedQuery(query, column_start, column_finish);
}

string SQLManager::getFullUserName(int userID)
{
    Query* temp_query = new Query;
    string query;

    query = "select LastName + FirstName from Users where UserID = " + to_string(userID);
    return temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1);
}

string SQLManager::getUserFirstName(int userID)
{
    Query* temp_query = new Query;
    string query;

    query = "select FirstName from Users where UserID = " + to_string(userID);
    return temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1);
}

string SQLManager::getUserLastName(int userID)
{
    Query* temp_query = new Query;
    string query;

    query = "select LastName from Users where UserID = " + to_string(userID);
    return temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1);
}

string SQLManager::getUserJoinedDate(int userID)
{
    Query* temp_query = new Query;
    string query;

    query = "select JoinDate from Users where UserID = " + to_string(userID);
    return temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1);
}

string SQLManager::getPassword(int userID)
{
    Query* temp_query = new Query;
    string query;

    query = "select PasswordHash from Users where UserID = " + to_string(userID);
    return temp_query->makeCustomQuery(STR_TO_WSTR(query).c_str(), 1, QueryDelimiter::Null);
}

void SQLManager::setUserPassword(int userID, string newPassword)
{
    //Make use of Hasher
    Query* temp_query = new Query;
    string query;
    //
    query = "update Users set PasswordHash = '" +
        HASH->getPasswordHash(newPassword) +
        "' where UserID = " +
        to_string(userID);

    temp_query->insertData(STR_TO_WSTR(query));
}

string SQLManager::getAllUserData(int userID)
{
    Query* temp_query = new Query;
    string query;

    query = "select * from Users where UserID = " + to_string(userID);
    return temp_query->makeRangedQuery(STR_TO_WSTR(query).c_str(), 1, 9);
}

bool SQLManager::authentifyUser(string first_name, string password_string)
{
    int seed = HASH->extractSeed(getPassword(getUserID(first_name)));

    Query* temp_query = new Query;
    wstring query_wstring;

    query_wstring = L"select FirstName + PasswordHash from Users where FirstName = '" +
        STR_TO_WSTR(first_name) +
        L"' and PasswordHash = '" +
        STR_TO_WSTR(HASH->getPasswordHash(password_string, seed)) +
        L"'";

    string return_string = temp_query->makeCustomQuery(query_wstring.c_str(), 1);

    if (return_string.length() != first_name.length() + HASH->getPasswordHash(password_string, seed).length() + 1) //+1 for the space after the query ends
        return false;
    return true;
}

void SQLManager::insertNewUser(string queryBuffer)
{
    Query* temp_query = new Query;
    string query;

    query = "USE Bomber INSERT INTO Users(UserRole, LastName, FirstName, PasswordHash, JoinDate) VALUES " +
        queryBuffer;

    temp_query->insertData(STR_TO_WSTR(query));
}

void SQLManager::insertNonUser(string queryBuffer)
{
    Query* temp_query = new Query;
    string query;

    query = "USE Bomber INSERT INTO Users(UserRole, LastName, FirstName, PasswordHash, JoinDate) VALUES " +
        queryBuffer;

    temp_query->insertData(STR_TO_WSTR(query));
}


SQLManager::~SQLManager()
{
    destroyInstance();
    cout << "SQL Manager shutting down." << endl;
}