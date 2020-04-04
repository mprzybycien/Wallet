#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int userId;
    string userName;
    string userSurname;
    string userLogin;
    string userPassword;

public:
    void setId(int newId);
    void setName(string newName);
    void setSurname(string newSurname);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    int getId();
    string getName();
    string getSurname();
    string getLogin();
    string getPassword();
};

#endif
