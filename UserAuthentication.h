#ifndef USERAUTHENTICATION_H
#define USERAUTHENTICATION_H

#include <string>
using namespace std;

enum UserType
{
    STUDENT,
    TEACHER,
    INVALID
};

struct UserData
{
    string password;
    UserType userType;
};

class UserAuthentication
{
public:
    static void registerUser(string &username, string &password, UserType userType);
    static UserType authenticate(string &username, string &password);
};

#endif
