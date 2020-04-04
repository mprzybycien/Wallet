#ifndef MYFINANCES_H
#define MYFINANCES_H

#include <iostream>
#include "UserManager.h"

using namespace std;

class MyFinances
{
    UserManager userManager;

    public:
    MyFinances( string usersFileName):userManager(usersFileName){};

    void registration();
    void logIn();
};

#endif
