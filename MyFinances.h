#ifndef MYFINANCES_H
#define MYFINANCES_H

#include <iostream>
#include "UserManager.h"
#include "TransactionManager.h"

using namespace std;

class MyFinances
{
    UserManager userManager;
    TransactionManager *transactionManager;

    public:
    MyFinances(string usersFileName):userManager(usersFileName)
    {
        transactionManager = NULL;
    };

    ~MyFinances()
    {
        delete transactionManager;
        transactionManager = NULL;
    };

    void registration();
    void logIn();
    void addNewIncome();
    void addNewExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showSelectedPeroidBalance();

    bool isUserLogedIn();
    void logOut();
};

#endif
