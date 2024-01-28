#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

Student::Student(string uname, string pwd, int id)
    : User(uname, pwd, UserType::STUDENT), studentID(id) {}

Student::~Student() {}

void Student::display_info()
{
    cout << "student id is:" << studentID << endl;
}

void Student::enroll_course()
{
    int course_id;
    string c1, c2;
    // cout << "No Courses";
    cout << "Enter course_id";
    cin >> course_id;
    ifstream ip("course_list.txt");
    if (!ip.is_open())
    {
        cerr << "Error opening File";
    }
    string line;
    while (getline(ip, line))
    {
        istringstream iss(line);
        getline(iss, c1, '\t');
        getline(iss, c2, '\t');
        int c = stoi(c2);
        if (c == course_id)
        {
            cout << "Selected course" << endl;
            cout << line << endl;
        }
    }
    ip.close();
}

void Student::display_course_list()
{
    ifstream ip("course_list.txt");
    if (!ip.is_open())
    {
        cerr << "Error opening File";
    }
    string line;
    while (getline(ip, line))
    {
        cout << line << endl;
    }
    ip.close();
}

void Student::displaymenu()
{
    while (1)
    {
        int choice;
        cout << "1)Display personal info" << endl
             << "2)dispaly available course list" << endl
             << "3)enroll course" << endl
             << "4)Log out" << endl;
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
            display_course_list();
            break;
        }
        case 3:
        {
            enroll_course();
            break;
        }
        case 4:
        {
            return;
        }

        default:
            break;
        }
    }
}