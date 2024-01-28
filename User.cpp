#include "User.h"
#include <iostream>
using namespace std;

User::User(string uname, string pwd, UserType type) : username(uname), password(pwd), userType(type) {}

User::~User() {}

User::User() {}

void User::displaymenu() {}
