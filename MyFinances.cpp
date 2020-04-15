#include <iostream>
#include "MyFinances.h"
#include "GeneralMethods.h"

using namespace std;

void MyFinances::registration()
{
    userManager.registration();
}

void MyFinances::logIn()
{
    userManager.logIn();
    if (userManager.isUserLogedIn())
    {
        transactionManager = new TransactionManager (userManager.getLogedInUserId());
    }
}

bool MyFinances::isUserLogedIn()
{
    userManager.isUserLogedIn();
}

void MyFinances::addNewIncome()
{
    transactionManager -> addNewIncome();
}

void MyFinances::addNewExpense()
{
    transactionManager -> addNewExpense();
}

void MyFinances::showCurrentMonthBalance()
{
    transactionManager -> showCurrentMonthBalance();
}

void MyFinances::showPreviousMonthBalance()
{
    transactionManager -> showPreviousMonthBalance();
}

void MyFinances::showSelectedPeroidBalance()
{
    transactionManager -> showSelectedPeroidBalance();
}

void MyFinances::logOut()
{
    userManager.setZeroAsLogedInUserId();
    delete transactionManager;
    transactionManager = NULL;
}

void MyFinances::changePassword()
{
    userManager.changePassword();
}

