#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
using namespace std;

class Student : public User
{
private:
    int studentID;

public:
    Student(string uname, string pwd, int id);
    ~Student() override;
    void displaymenu() override;
};

#endif
