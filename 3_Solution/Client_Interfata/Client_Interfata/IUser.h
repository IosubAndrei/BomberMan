#pragma once
#include <iostream>

class IUSer
{
public:

	virtual void printUser() = 0;
	virtual void changePswd() = 0;

	//set
	virtual void setUserFirstName(std::string) = 0;
	virtual void setUserLastName(std::string) = 0;
	virtual void setPassword(std::string) = 0;
	virtual void setJoinedDate(std::string) = 0;
	virtual void setRole(int) = 0;
	virtual void setUserID(int) = 0;
	virtual void setConnectionData(std::string _LastName, std::string _FirstName, std::string _JoinedDate, int _ID, int _role) = 0;

	//get
	virtual	std::string getUserFirstName() = 0;
	virtual std::string getUserLastName() = 0;
	virtual std::string getUserFullName() = 0;
	virtual std::string getUserJoinDate() = 0;
	virtual int getUserID() = 0;
	virtual int getUserRole() = 0;
};
