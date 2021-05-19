#include "FactoryUser.h"
#include "Admin.h"
#include "User.h"


IUSer* FactoryUser::createUserAdmin()
{
    return new Admin;
}

IUSer* FactoryUser::createUser()
{
    return new User;
}
