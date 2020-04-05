#ifndef INCOMESFILE_H
#define INCOMESFILE_H
#include <iostream>
#include "income.h"
#include "expense.h"
#include "Markup.h"
#include "vector"

using namespace std;

class IncomesFile
{
    //CMarkup xml;

public:
    void appendIncomeToFile(Income income);
};

#endif
