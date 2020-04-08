#include "ExpensesFile.h"

void ExpensesFile::appendExpenseToFile(Expense expense)
{
    bool fileExists = xml.Load("Expenses.xml");
    if(!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
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
    xml.AddElem("amount", GeneralMethods::convertFloatToString(expense.getAmount()));

    xml.Save("Expenses.xml");
}

vector <Expense> ExpensesFile::loadLogedInUserExpenses(int logedInUserId)
{
    Expense expense;
    vector <Expense> expenses;
    bool fileExists = xml.Load("Expenses.xml");
    if(!fileExists)
    {
        cout << "Plik z wydatkami jeszcze nie istnieje." << endl;;
    }

    xml.FindElem("Expenses");
    xml.IntoElem();

    while(xml.FindElem("Expense"))
    {
        xml.IntoElem();
        xml.FindElem("id");
        lastExpenseId = atoi(xml.GetData().c_str());

        xml.FindElem("userId");
        if (atoi(xml.GetData().c_str()) == logedInUserId)
        {
            xml.ResetMainPos();
            xml.FindElem("id");
            expense.setId(atoi(xml.GetData().c_str()));

            xml.FindElem("userId");
            expense.setUserId(atoi(xml.GetData().c_str()));

            xml.FindElem("date");
            expense.setDate(atoi(xml.GetData().c_str()));

            xml.FindElem("title");
            expense.setTitle(xml.GetData());

            xml.FindElem("amount");
            expense.setAmount(atof(xml.GetData().c_str()));

            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
    return expenses;
}

int ExpensesFile::getLastExpenseId()
{
    return lastExpenseId;
}

void ExpensesFile::setLastExpenseId(int newLastExpenseId)
{
    lastExpenseId = newLastExpenseId;
}
