#include "Transaction.h"

void Transaction::setId(int newId)
{
    if (newId >= 0)
        id = newId;
}

void Transaction::setUserId(int newUserId)
{
    if (newUserId >= 0)
        userId = newUserId;
}
void Transaction::setDate(int newDate)
{
        date = newDate;
}
void Transaction::setName(string newName)
{
    name = newName;
}
void Transaction::setAmount(float newAmount)
{
    amount = newAmount;
}

int Transaction::getId()
{
    return id;
}
int Transaction::getUserId()
{
    return userId;
}
int Transaction::getDate()
{
    return date;
}

string Transaction::getName()
{
    return name;
}

float Transaction::getAmount()
{
    return amount;
}
