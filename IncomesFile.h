#ifndef INCOMESFILE_H
#define INCOMESFILE_H
#include <iostream>
#include "income.h"
#include "Markup.h"
#include "vector"
#include "GeneralMethods.h"

using namespace std;

class IncomesFile
{
    CMarkup xml;
    int lastIncomeId;

public:
    void appendIncomeToFile(Income income);
    vector <Income> loadLogedInUserIncomes(int logedInUserId);

    IncomesFile()
    {
        lastIncomeId = 0;
    };
    int getLastIncomeId();
    void setLastIncomeId(int newLastIncomeId);
};

#endif
