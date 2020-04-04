#include "GeneralMethods.h"
#include "algorithm"

string GeneralMethods::convertIntToString(int integer)
{
    ostringstream ss;
    ss << integer;
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

char GeneralMethods::loadCharacter()
{
    string ins = "";
    char character  = {0};

    while (true)
    {
        getline(cin, ins);

        if (ins.length() == 1)
        {
            character = ins[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
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

