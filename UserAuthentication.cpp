#include <iostream>
#include "UserAuthentication.h"
#include <unordered_map>
using namespace std;

unordered_map<std::string, UserData> userDatabase;

void UserAuthentication::registerUser(string &username, string &password, UserType userType)
{
    UserData userData{password, userType};
    userDatabase[username] = userData;
}

UserType UserAuthentication::authenticate(string &username, string &password)
{
    auto it = userDatabase.find(username);
    if (it != userDatabase.end() && it->second.password == password)
    {
        return it->second.userType;
    }
    else
    {
        return UserType::INVALID;
    }
}
