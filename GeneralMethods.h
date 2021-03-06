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
    static string convertFloatToString(float float_);
    static int convertStringToInt(string integer);
    static string replaceFirstLetterUpperRemainsLower(string text);
};

#endif
