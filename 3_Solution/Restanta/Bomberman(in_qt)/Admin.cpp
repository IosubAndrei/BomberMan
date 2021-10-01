#include "Admin.h"

Admin::Admin(std::string _userData, char delim) :
	User(_userData, delim)
{

}

Admin::Admin()
{
}

void Admin::seeConnectedUsers()
{
}

void Admin::registerNewUser(std::string _userData)//make use of SQL Manager 
{

}

void Admin::deleteUser(std::string userFullName)//make user of SQL Manager
{

}

Admin::~Admin()
{

}

