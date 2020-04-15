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
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

    public:
    MyFinances(string usersFileName, string incomesFileName, string expensesFileName):
    userManager(usersFileName),
    INCOMES_FILE_NAME(incomesFileName),
    EXPENSES_FILE_NAME(expensesFileName)
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
    void changePassword();

    void addNewIncome();
    void addNewExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showSelectedPeroidBalance();

    bool isUserLogedIn();
    void logOut();

};

#endif
