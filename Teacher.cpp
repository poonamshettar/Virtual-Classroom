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
    cout << "Teacher id is:" << subject << endl;
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
    op << subject << '\t' << course_id++ << "\t" << new_user_subject << endl;
    op.close();
}

void Teacher::Enrolled_Students()
{
    string temp;
    cout << "Enter the list wanted" << endl;
    cin >> temp;
    cout << "List of enrolled students" << endl;
    temp = temp + ".txt";
    ifstream ip(temp);
    if (!ip.is_open())
    {
        cerr << "No Students Registerd" << endl;
    }
    string line;
    while (getline(ip, line))
    {
        cout << line << endl;
    }
    ip.close();
    cout << endl;
}

void Teacher::displaymenu()
{
    cout << endl
         << "Teacher logged in" << endl;

    while (1)
    {
        int choice;
        cout << "1)Display personal info" << endl
             << "2)Add course" << endl
             << "3)Enrolled students" << endl
             << "4)Assign grades" << endl
             << "5)See assigned grades" << endl
             << "6)Log out" << endl;
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
            Enrolled_Students();
            break;
        case 4:
            assign_grades();
            break;
        case 5:
            display_grades();
            break;
        case 6:
        {
            return;
        }

        default:
            break;
        }
    }
}
