#include "ExpensesFile.h"

void ExpensesFile::appendExpenseToFile(Expense expense)
{
    CMarkup xml;
    bool fileExists = xml.Load("Expenses.xml");
    if(!fileExists)
    {
        xml.AddElem("Expenses");
    }
    xml.FindElem("Expenses");
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("id", expense.getId());
    xml.AddElem("userId", expense.getUserId());
    xml.AddElem("date", expense.getDate());
    xml.AddElem("title", expense.getTitle());
    xml.AddElem("amount", expense.getAmount());

    xml.Save("Expenses.xml");
}
