#pragma once
#include "IUser.h"

class User: public IUSer
{
protected:
	std::string lastName;
	std::string firstName;
	std::string joinedDate;
	std::string password;

	int userID;
    int role;

public:
	User(std::string userData);
	User();

    virtual void printUser() {};
    virtual void changePswd() {};


    //setere
    void setUserFirstName(std::string) override;
    void setUserLastName(std::string) override;
    void setPassword(std::string) override;
    void setJoinedDate(std::string) override;
    void setUserID(int) override;
    void setRole(int) override;

    void setConnectionData(std::string _LastName, std::string _FirstName, std::string _JoinedDate, int _ID, int _role) override;

    //get-ere
    std::string getUserFirstName() override;
    std::string getUserLastName() override;
    std::string getUserFullName() override;
    std::string getUserJoinDate() override;
    int getUserID() override;
    int getUserRole() override;

    virtual ~User();

};

