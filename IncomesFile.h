#ifndef INCOMESFILE_H
#define INCOMESFILE_H
#include <iostream>
#include <vector>
#include "Income.h"
#include "Markup.h"
#include "GeneralMethods.h"
#include "TextFile.h"

using namespace std;

class IncomesFile : public TextFile
{
    const string INCOMES_FILE_NAME;
    int lastIncomeId;

public:
    IncomesFile(string INCOMESFILENAME) : INCOMES_FILE_NAME (INCOMESFILENAME)
    {
        lastIncomeId = 0;
    };
    void appendIncomeToFile(Income income);
    vector <Income> loadLogedInUserIncomes(int logedInUserId);
    int getLastIncomeId();
    void setLastIncomeId(int newLastIncomeId);
};

#endif
