#include <iostream>
#include "MyFinances.h"

using namespace std;

int main()
{
    MyFinances myFinances ("Users.xml");
    //myFinances.registration();
    myFinances.logIn();
    //myFinances.addNewIncome();
    //myFinances.addNewIncome();
    myFinances.addNewExpense();
    myFinances.addNewExpense();

    myFinances.showIncomesDetailsOfLogInUserSortedByDate();
    myFinances.showLogedInUserExpenses();
    return 0;
}

