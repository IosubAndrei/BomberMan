#pragma once
#include <iostream>
#include <locale>
#include <codecvt>
#include <string>

#include "Query.h"
#include "PswdHash.h"
#include "Parser.h"

using namespace std;

#define STR_TO_WSTR(str) wstring_convert<codecvt_utf8<wchar_t>>().from_bytes(str) //normal string to wide string convertor
#define WSTR_TO_STR(str) wstring_convert<codecvt_utf8<wchar_t>>().to_bytes(str); //wide string to normal string convertor

#define PARSER Parser::getInstance()
#define HASH PswdHash::getInstance()

class SQLManager
{
private:
    SQLManager();
    ~SQLManager();
    SQLManager(SQLManager& copyInstance) = delete;

    string makeRangedQuery(const wchar_t* query, int column_start, int column_finish);
    string makeCustomQuery(const wchar_t* query, int column); //E.g. query: "SELECT * FROM Employees", /// column e coloana pe care o vreau


    void destroyInstance();

    static SQLManager* instance;

public:
    static SQLManager* getInstance();

    string getAllUserNames();
    int getUserRole(string _firstName);
    int getUserID(string _firstName);
    string getFullUserName(int userID);
    string getUserFirstName(int userID);
    string getUserLastName(int userID);
    string getUserJoinedDate(int userID);
    string getPassword(int userID);

    void setUserPassword(int userID, string newPassword);
    string getAllUserData(int userID);
    bool authentifyUser(string name_user, string password_string);
    void insertNewUser(string queryBuffer);
    void insertNonUser(string queryBuffer);
};

