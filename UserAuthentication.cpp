#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include "UserAuthentication.h"
#include <unordered_map>
using namespace std;

unordered_map<string, UserData> userDatabase;

void UserAuthentication::registerUser(string &username, string &password, UserType userType, User *userObject)
{
    UserData userData{password, userType, userObject}; // storing user data in struct
    userDatabase[username] = userData;                 // storing in unordered map
}

UserType UserAuthentication::authenticate(string &username, string &password)
{
    auto it = userDatabase.find(username);
    if (it == userDatabase.end())
    {
        return UserType::INVALID1; // for no username found
    }
    if (it->second.password == password)
    {
        return it->second.userType;
    }
    else
    {
        return UserType::INVALID2; // for password wrong
    }
}
User *UserAuthentication::getRegisteredUser(const std::string &username)
{
    auto it = userDatabase.find(username);
    if (it != userDatabase.end())
    {
        return it->second.user;
    }
    return nullptr;
}
