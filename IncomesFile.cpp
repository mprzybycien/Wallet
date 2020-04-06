#include "IncomesFile.h"

void IncomesFile::appendIncomeToFile(Income income)
{
    CMarkup xml;
    bool fileExists = xml.Load("Incomes.xml");
    if(!fileExists)
    {
        xml.AddElem("Incomes");
    }
    xml.FindElem("Incomes");
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("id", income.getId());
    xml.AddElem("userId", income.getUserId());
    xml.AddElem("date", income.getDate());
    xml.AddElem("title", income.getTitle());
    xml.AddElem("amount", income.getAmount());

    xml.Save("Incomes.xml");
}

vector <Income> IncomesFile::loadLogedInUserIncomes(int logedInUserId)
{
    CMarkup xml;
    Income income;
    vector <Income> incomes;
    bool fileExists = xml.Load("Incomes.xml");
    if(!fileExists)
    {
        cout << "Plik z przychodami jeszcze nie istnieje." << endl;;
    }
    xml.FindElem("Incomes");
    xml.IntoElem();

    while(xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem("userId");
        if (atoi(xml.GetData().c_str()) == logedInUserId)
        {
            income.setUserId(atoi(xml.GetData().c_str()));

            xml.FindElem("id");
            income.setId(atoi(xml.GetData().c_str()));

            xml.FindElem("date");
            income.setDate(atoi(xml.GetData().c_str()));

            xml.FindElem("title");
            income.setTitle(xml.GetData());

            xml.FindElem("amount");
            income.setAmount(atof(xml.GetData().c_str()));

            incomes.push_back(income);

            xml.OutOfElem();
        }
    }
    return incomes;
}
