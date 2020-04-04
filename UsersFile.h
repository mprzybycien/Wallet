#ifndef USERSFILE_H
#define USERSFILE_H
#include <iostream>
#include "User.h"
#include "Markup.h"
#include "vector"


using namespace std;

class UsersFile //:public TextFile
{
    const string usersFileName;
    CMarkup xml;
    //User user;

public:
    UsersFile(string USERSFILENAME) : usersFileName (USERSFILENAME) {};
    void appendUserToFile(User user);
    vector <User> loadUsersFromFile();

};

#endif
