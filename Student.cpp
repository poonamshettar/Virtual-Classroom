#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string uname, string pwd, int id)
    : User(uname, pwd, UserType::STUDENT), studentID(id) {}

Student::~Student() {}

void Student::display_info()
{
    cout << studentID << endl;
}

void Student::enroll_course()
{
    cout << "No cousre available";
}

void Student::displaymenu()
{
    while (1)
    {
        int choice;
        cout << "1)Display personal info" << endl
             << "2)enroll course" << endl
             << "3)Log out" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            display_info();
            break;
        }
        case 2:
        {
            enroll_course();
            break;
        }
        case 3:
        {
            return;
        }

        default:
            break;
        }
    }
}