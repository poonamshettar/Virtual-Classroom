#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Course.h"
using namespace std;

class Student : public User, public Course
{
private:
    int studentID;

public:
    Student(string uname, string pwd, int id);
    ~Student() override;
    void displaymenu() override;
    void display_info();
    void enroll_course();
    void write_enrollment(string courseInfo);
    void display_course_list();
};

#endif
