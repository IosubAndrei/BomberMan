#include "FactoryUser.h"
#include "Admin.h"
#include "User.h"


IUSer* FactoryUser::createUserAdmin(std::string user_info, char delim)
{
    return new Admin(user_info, delim);
}

IUSer* FactoryUser::createUser(std::string user_info, char delim)
{
    return new User(user_info, delim);
}
