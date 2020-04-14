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
