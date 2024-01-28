#include <iostream>
#include "VirtualClassroom.h"
#include "UserAuthentication.h"
#include "Teacher.h"
#include "Student.h"

using namespace std;
void VirtualClassroom::run()
{
    int x;
    UserAuthentication auth;
    User *currentUser;
    while (1)
    {
        cout << "1)Log in\n2)Regsiter\n3)exit\n";
        cin >> x;
        switch (x)
        {

        case 1:
        {
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            UserType userType = auth.authenticate(username, password);
            if (userType == UserType::INVALID)
            {
                cout << "Username or Password wrong" << endl;
            }
            else if (userType == UserType::STUDENT)
            {
                cout << "Logged in as student" << endl;
                Student student(username, password, 4);
                currentUser = new Student(username, password, 4);
                currentUser->displaymenu();
            }
            else if (userType == UserType::TEACHER)
            {
                cout << "Logged in as teacher" << endl;
                currentUser = new Teacher(username, password, "abhi");
                currentUser->displaymenu();
            }
            break;
        }
        case 2:
        {
            string username, password;
            int userTypeInt;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            cout << "Enter user type (0 for student, 1 for teacher): ";
            cin >> userTypeInt;

            UserType userType = static_cast<UserType>(userTypeInt);

            auth.registerUser(username, password, static_cast<UserType>(userType));
            cout << "Registration successful! You can now log in." << endl;
            break;
        }
        case 3:
        {
            exit(0);
        }
        default:
            cout << "Invalid Entry" << endl;
        }
    }
}
