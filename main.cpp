#include <iostream>
#include "MyFinances.h"

using namespace std;

int main()
{
    MyFinances myFinances ("Users.xml");
    myFinances.registration();
    myFinances.logIn();
    return 0;
}

