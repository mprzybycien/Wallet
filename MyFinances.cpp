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
        new TransactionManager(userManager.getLogedInUserId());
    }
}

void MyFinances::addNewIncome()
{
    transactionManager -> addNewIncome();
}
