#pragma once
#include "User.h"
class Admin :
    public User
{
public:
    Admin(std::string, char);
    Admin();

    void seeConnectedUsers();
    void registerNewUser(std::string);
    void deleteUser(std::string);

    ~Admin();
};

