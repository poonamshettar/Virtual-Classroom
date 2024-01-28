#ifndef USERAUTHENTICATION_H
#define USERAUTHENTICATION_H

#include <string>
#include "UserType.h"
#include "User.h"
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
    User *getRegisteredUser(const string &username); // If getRegisteredUser did not have a const qualifier, you wouldn't be able to call it on a const object of the UserAuthentication class.
};

#endif
