#ifndef GENERALMETHODS_H
#define GENERALMETHODS_H

#include <iostream>
#include "User.h"
#include <fstream>
#include <sstream>

using namespace std;

class GeneralMethods
{
public:
    static string insertTextLine();
    static string convertIntToString(int integer);
    static int convertStringToInt(string integer);
    static char loadCharacter();
    static string replaceFirstLetterUpperRemainsLower(string text);
};

#endif
