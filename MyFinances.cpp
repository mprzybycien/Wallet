#include <iostream>
#include "MyFinances.h"

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
        new TransactionManager();
        cout << "dobrze zalogowany" << endl;
    }
}
