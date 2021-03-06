#include "IncomesFile.h"

void IncomesFile::appendIncomeToFile(Income income)
{
    bool fileExists = xml.Load(INCOMES_FILE_NAME.c_str());
    if(!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
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
    xml.AddElem("amount", GeneralMethods::convertFloatToString(income.getAmount()));

    xml.Save(INCOMES_FILE_NAME.c_str());
}

vector <Income> IncomesFile::loadLogedInUserIncomes(int logedInUserId)
{
    Income income;
    vector <Income> incomes;
    bool fileExists = xml.Load(INCOMES_FILE_NAME.c_str());
    if(!fileExists)
    {
        cout << "Plik z przychodami jeszcze nie istnieje." << endl;;
    }

    xml.FindElem("Incomes");
    xml.IntoElem();


    while(xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem("id");
        lastIncomeId = atoi(xml.GetData().c_str());

        xml.FindElem("userId");
        if (atoi(xml.GetData().c_str()) == logedInUserId)
        {
            xml.ResetMainPos();
            xml.FindElem("id");
            income.setId(atoi(xml.GetData().c_str()));

            xml.FindElem("userId");
            income.setUserId(atoi(xml.GetData().c_str()));

            xml.FindElem("date");
            income.setDate(atoi(xml.GetData().c_str()));

            xml.FindElem("title");
            income.setTitle(xml.GetData());

            xml.FindElem("amount");
            income.setAmount(atof(xml.GetData().c_str()));

            incomes.push_back(income);
        }
        xml.OutOfElem();
    }
    return incomes;
}

int IncomesFile::getLastIncomeId()
{
    return lastIncomeId;
}

void IncomesFile::setLastIncomeId(int newLastIncomeId)
{
    lastIncomeId = newLastIncomeId;
}


