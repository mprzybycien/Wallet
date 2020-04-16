#ifndef USERSFILE_H
#define USERSFILE_H
#include <iostream>
#include "User.h"
#include "Markup.h"
#include "vector"


using namespace std;

class UsersFile
{
    const string USERS_FILE_NAME;
    CMarkup xml;
public:
    UsersFile(string USERSFILENAME) : USERS_FILE_NAME (USERSFILENAME) {};
    void appendUserToFile(User user);
    vector <User> loadUsersFromFile();
    void removeFile(string USERS_FILE_NAME);
    void saveUsersVectorToFile (vector <User> &users);
};

#endif
