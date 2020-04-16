#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H
#include <iostream>
#include <vector>
#include "Expense.h"
#include "Markup.h"
#include "GeneralMethods.h"
#include "TextFile.h"

using namespace std;

class ExpensesFile : public TextFile
{
    const string EXPENSES_FILE_NAME;
    int lastExpenseId;

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
