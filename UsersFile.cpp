#include "UsersFile.h"
#include "User.h"
#include "vector"
#include <cstdlib>
#include <windows.h>
#include "Markup.h"

void UsersFile::appendUserToFile(User user)
{
    bool fileExists = xml.Load(usersFileName.c_str());
    if(!fileExists)
    {
        xml.AddElem("Users");
    }
    xml.FindElem("Users");
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("userId", user.getId());
    xml.AddElem("userName", user.getName());
    xml.AddElem("userSurname", user.getSurname());
    xml.AddElem("userLogin", user.getLogin());
    xml.AddElem("userPassword", user.getPassword());

    xml.Save(usersFileName.c_str());
}

vector <User> UsersFile::loadUsersFromFile()
{
    User user;
    vector <User> users;

    bool fileExists = xml.Load(usersFileName.c_str());
    if(!fileExists)
    {
        cout << "Plik nie istnieje." << endl;
    }
    else
    {
        xml.FindElem("Users");
        xml.IntoElem();

        while(xml.FindElem("User"))
        {
            xml.IntoElem();
            xml.FindElem("userId");
            user.setId(atoi(xml.GetData().c_str()));

            xml.FindElem("userName");
            user.setName(xml.GetData());

            xml.FindElem("userSurname");
            user.setSurname(xml.GetData());

            xml.FindElem("userLogin");
            user.setLogin(xml.GetData());

            xml.FindElem("userPassword");
            user.setPassword(xml.GetData());

            users.push_back(user);

            xml.OutOfElem();
        }
    }
    return users;
}
