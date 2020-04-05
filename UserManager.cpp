#include <iostream>
#include <windows.h>
#include <conio.h>
#include "UserManager.h"
#include "GeneralMethods.h"
#include <stdexcept>
#include <string>
#include "UserManager.h"
#include "GeneralMethods.h"

using namespace std;

void UserManager::registration()
{
    User user = enterNewUserData();

    users.push_back(user);

    usersFile.appendUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::enterNewUserData()
{
    User user;
    user.setId(getNewUserId());

    string name, surname, login, password;

    cout << "Podaj imie: ";
    name = GeneralMethods::replaceFirstLetterUpperRemainsLower(GeneralMethods::insertTextLine());
    user.setName(name);

    cout << "Podaj nazwisko: ";
    surname = GeneralMethods::insertTextLine();
    user.setSurname(surname);

    do
    {
        cout << "Podaj login: ";
        login = GeneralMethods::insertTextLine();
        user.setLogin(login);
    }
    while (isLoginExists(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    password = GeneralMethods::insertTextLine();
    user.setPassword(password);

    return user;
}

int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isLoginExists(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

int UserManager::logIn()
{
    string log = "", pass = "";

    cout << "Podaj login: ";
    log = GeneralMethods::insertTextLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == log)
        {
            for (int attempts = 3; attempts > 0; attempts--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << attempts << ": ";
                pass = GeneralMethods::insertTextLine();

                if (itr -> getPassword() == pass )
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    logedInUserId = itr -> getId();
                    return logedInUserId;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

bool UserManager::isUserLogedIn()
{
    if (logedInUserId > 0)
        return true;
    else
        return false;
}

int UserManager::getLogedInUserId()
{
    return logedInUserId;
}
