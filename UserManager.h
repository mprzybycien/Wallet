#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "UsersFile.h"
#include "GeneralMethods.h"

using namespace std;

class UserManager
{
    vector <User> users;
    UsersFile usersFile;
    int logedInUserId;

    User enterNewUserData();
    bool isLoginExists(string login);
    int getNewUserId();

    public:
    UserManager(string usersFileName):usersFile(usersFileName)
    {
        users = usersFile.loadUsersFromFile();
        logedInUserId = 0;
    }
    bool isUserLogedIn();
    void registration();
    int logIn();
    int getLogedInUserId();
    void setZeroAsLogedInUserId();
    void changePassword();
};

#endif
