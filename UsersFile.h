#ifndef USERSFILE_H
#define USERSFILE_H
#include <iostream>
#include <vector>
#include "User.h"
#include "Markup.h"
#include "TextFile.h"

using namespace std;

class UsersFile : public TextFile
{
    const string USERS_FILE_NAME;
public:
    UsersFile(string USERSFILENAME) : USERS_FILE_NAME (USERSFILENAME) {};
    void appendUserToFile(User user);
    vector <User> loadUsersFromFile();
    void removeFile(string USERS_FILE_NAME);
    void saveUsersVectorToFile (vector <User> &users);
};

#endif
