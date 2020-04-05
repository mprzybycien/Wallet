#include "User.h"

void User::setId(int newId)
{
    if (newId >= 0)
        userId = newId;
}
void User::setName(string newName)
{
    userName = newName;
}
void User::setLogin(string newLogin)
{
    userLogin = newLogin;
}
void User::setSurname(string newSurname)
{
    userSurname = newSurname;
}
void User::setPassword(string newPassword)
{
    userPassword = newPassword;
}

int User::getId()
{
    return userId;
}
string User::getName()
{
    return userName;
}

string User::getSurname()
{
    return userSurname;
}

string User::getLogin()
{
    return userLogin;
}
string User::getPassword()
{
    return userPassword;
}
