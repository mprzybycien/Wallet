#include "GeneralMethods.h"
#include "algorithm"

string GeneralMethods::convertIntToString(int integer)
{
    ostringstream ss;
    ss << integer;
    string str = ss.str();
    return str;
}

string GeneralMethods::convertFloatToString(float float_)
{
    ostringstream ss;
    ss << float_;
    string str = ss.str();
    return str;
}

string GeneralMethods::insertTextLine()
{
    string ins = "";
    cin.clear();
    cin.sync();
    getline(cin, ins);
    return ins;
}

int GeneralMethods::convertStringToInt(string integer)
{
    int convInteger;
    istringstream iss(integer);
    iss >> integer;
    return convInteger;
}

string GeneralMethods::replaceFirstLetterUpperRemainsLower(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

