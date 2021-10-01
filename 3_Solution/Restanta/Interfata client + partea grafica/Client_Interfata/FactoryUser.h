#pragma once
#include <iostream>
#include <string>

class IUSer;

class FactoryUser
{
public:
	static IUSer* createUserAdmin();
	static IUSer* createUser();
};

