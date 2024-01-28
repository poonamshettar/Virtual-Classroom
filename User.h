#ifndef USER_H
#define USER_H

#include <string>
#include "UserType.h"

using namespace std;

class User
{
private:
    string password;
    UserType userType;

public:
    string username;
    User();
    User(string uname, string pwd, UserType type);
    virtual ~User();
    virtual void displaymenu();
};

#endif
