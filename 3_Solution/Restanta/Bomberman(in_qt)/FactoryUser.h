#pragma once
#include <iostream>
#include <string>

class IUSer;

class FactoryUser
{
public:
	static IUSer* createUserAdmin(std::string user_info, char delim);
	static IUSer* createUser(std::string user_info, char delim);
};

