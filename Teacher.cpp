#include "Teacher.h"
#include <iostream>
#include <fstream>
using namespace std;

Teacher::Teacher(string uname, string pwd, int sub)
    : User(uname, pwd, UserType::TEACHER), subject(sub) {}

Teacher::~Teacher() {}
int course_id = 0;
void Teacher::display_info()
{
    cout << "Teacher\n";
}
void Teacher::add_course()
{
    cout << "Enter The course to be added" << endl;
    string new_user_subject;
    cin >> new_user_subject;
    ofstream op("course_list.txt", ios::app);
    if (!op.is_open())
    {
        cerr << "Error opening File";
    }
    op << subject << '\t' << course_id++ << '\t' << new_user_subject << endl;
    op.close();
}

void Teacher::displaymenu()
{
    cout << "Teacher logged in\n";
    while (1)
    {
        int choice;
        cout << "1)Display personal info" << endl
             << "2)Add course" << endl
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
            add_course();
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

// void Teacher::read_()
// {
//     ofstream op("course_list.txt", ios::app);
//     if (op.is_open())
//     {
//         cerr << "Error opening File";
//     }
// }