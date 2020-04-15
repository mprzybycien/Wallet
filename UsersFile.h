#ifndef USERSFILE_H
#define USERSFILE_H
#include <iostream>
#include "User.h"
#include "Markup.h"
#include "vector"


using namespace std;

class UsersFile
{
    const string usersFileName;
    CMarkup xml;


public:
    UsersFile(string USERSFILENAME) : usersFileName (USERSFILENAME) {};
    void appendUserToFile(User user);
    vector <User> loadUsersFromFile();
    void removeFile(string usersFileName);
    void saveUsersVectorToFile (vector <User> &users);
};

#endif
