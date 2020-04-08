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

void MyFinances::showLogedInUserIncomes()
{
    transactionManager -> showLogedInUserIncomes();
}

void MyFinances::showLogedInUserExpenses()
{
    transactionManager -> showLogedInUserExpenses();
}
