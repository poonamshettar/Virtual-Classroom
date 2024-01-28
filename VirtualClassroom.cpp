#include <iostream>
#include "VirtualClassroom.h"
#include "UserAuthentication.h"

using namespace std;
void VirtualClassroom::run()
{
    int x;
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

            UserType userType = UserAuthentication::authenticate(username, password);
            if (userType == UserType::INVALID)
            {
                cout << "Username or Password wrong" << endl;
            }
            else if (userType == UserType::STUDENT)
            {
                cout << "Logged in as student" << endl;
            }
            else if (userType == UserType::TEACHER)
            {
                cout << "Logged in as teacher" << endl;
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

            UserAuthentication::registerUser(username, password, static_cast<UserType>(userType));
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
