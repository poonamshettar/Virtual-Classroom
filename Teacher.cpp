#include "Teacher.h"
#include <iostream>
using namespace std;

Teacher::Teacher(string uname, string pwd, string sub)
    : User(uname, pwd, UserType::TEACHER), subject(sub) {}

Teacher::~Teacher() {}

void Teacher::displaymenu()
{
    cout << "Teacher logged in";
}
