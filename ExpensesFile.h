#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H
#include <iostream>
#include "expense.h"
#include "Markup.h"
#include "vector"
#include "GeneralMethods.h"

using namespace std;

class ExpensesFile
{
    const string EXPENSES_FILE_NAME;
    int lastExpenseId;
    CMarkup xml;

public:
    ExpensesFile(string EXPENSESFILENAME) : EXPENSES_FILE_NAME(EXPENSESFILENAME)
    {
        lastExpenseId = 0;
    };
    void appendExpenseToFile(Expense expense);
    vector <Expense> loadLogedInUserExpenses(int logedInUserId);
    int getLastExpenseId();
    void setLastExpenseId(int newLastExpenseId);
};

#endif
