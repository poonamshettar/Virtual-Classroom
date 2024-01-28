#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string uname, string pwd, int id)
    : User(uname, pwd, UserType::STUDENT), studentID(id) {}

Student::~Student() {}

void Student::displaymenu()
{
    cout << "Student logged in";
}