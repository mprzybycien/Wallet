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
    int lastExpenseId;

public:
    void appendExpenseToFile(Expense expense);
    vector <Expense> loadLogedInUserExpenses(int logedInUserId);

    ExpensesFile()
    {
        lastExpenseId = 1;
    };
    int getLastExpenseId();
    void setLastExpenseId(int newLastExpenseId);
};

#endif
