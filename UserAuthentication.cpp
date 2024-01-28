#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include "UserAuthentication.h"
#include <unordered_map>
using namespace std;

unordered_map<string, UserData> userDatabase;

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
User *UserAuthentication::getRegisteredUser(const std::string &username)
{
    auto it = userDatabase.find(username);
    if (it != userDatabase.end())
    {
        if (it->second.userType == UserType::STUDENT)
        {
            return new Student(username, it->second.password, 4); // Adjust parameters accordingly
        }
        else if (it->second.userType == UserType::TEACHER)
        {
            return new Teacher(username, it->second.password, "teacherInfo"); // Adjust parameters accordingly
        }
        // Add more conditions for other user types if needed
    }
    return nullptr;
}
