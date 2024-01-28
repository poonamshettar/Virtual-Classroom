#ifndef TEACHER_H
#define TEACHER_H

#include "User.h"
using namespace std;

class Teacher : public User
{
private:
    std::string subject;

public:
    Teacher(string uname, string pwd, string sub);
    ~Teacher() override;
    virtual void displaymenu() override;
};

#endif
