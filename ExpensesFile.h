#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H
#include <iostream>
#include "income.h"
#include "expense.h"
#include "Markup.h"
#include "vector"

using namespace std;

class ExpensesFile
{

public:
    void appendExpenseToFile(Expense expense);
};

#endif
