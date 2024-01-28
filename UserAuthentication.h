#ifndef USERAUTHENTICATION_H
#define USERAUTHENTICATION_H

#include <string>
#include "UserType.h"
using namespace std;

struct UserData
{
    string password;
    UserType userType;
};

class UserAuthentication
{
public:
    void registerUser(string &username, string &password, UserType userType);
    UserType authenticate(string &username, string &password);
};

#endif
