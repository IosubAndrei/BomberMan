#include "User.h"

User::User(std::string userData)
{
	//Todo Constructor
}

User::User()
{
}

void User::setUserFirstName(std::string name)
{
	firstName = name;
}

void User::setUserLastName(std::string name)
{
	lastName = name;
}

void User::setPassword(std::string newPassword)///////Make use of the SQL Manager
{
	password = newPassword;
}

void User::setJoinedDate(std::string newJoinedDate)
{
	joinedDate = newJoinedDate;
}

void User::setUserID(int newID)
{
	userID = newID;
}

void User::setRole(int newRole)
{
	role = newRole;
}


void User::setConnectionData(std::string _LastName, std::string _FirstName, std::string _JoinedDate, int _ID, int _role)
{
	setUserFirstName(_FirstName);
	setUserLastName(_LastName);
	setJoinedDate(_JoinedDate);
	setUserID(_ID);
	setRole(_role);
}

std::string User::getUserFirstName()
{
	return firstName;
}

std::string User::getUserLastName()
{
	return lastName;
}

std::string User::getUserFullName()
{
	return firstName + lastName;
}

std::string User::getUserJoinDate()
{
	return joinedDate;
}

int User::getUserRole()
{
	return role;
}


int User::getUserID()
{
	return userID;
}

User::~User()
{
	lastName.erase();
	firstName.erase();
}

