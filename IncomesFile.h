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

public:
    void appendIncomeToFile(Income income);
    vector <Income> loadLogedInUserIncomes(int logedInUserId);
};

#endif
