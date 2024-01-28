#ifndef TEACHER_H
#define TEACHER_H

#include "User.h"
using namespace std;

class Teacher : public User
{
private:
    int subject;

public:
    Teacher(string uname, string pwd, int id_t);
    ~Teacher() override;
    virtual void displaymenu() override;
    void display_info();
    void add_course();
};

#endif
