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
