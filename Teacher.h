#ifndef TEACHER_H
#define TEACHER_H

#include "User.h"
#include "Course.h"
using namespace std;

class Teacher : public User, public Course
{
private:
    int subject;

public:
    Teacher(string uname, string pwd, int id_t);
    ~Teacher() override;
    virtual void displaymenu() override;
    void Enrolled_Students();
    void display_info();
    void add_course();
};

#endif
