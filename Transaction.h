#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Transaction
{
    int id;
    int userId;

    string title;
    float amount;

public:
    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setTitle(string newTitle);
    void setAmount(float newAmount);

    int getId();
    int getUserId();
    int getDate();
    string getTitle();
    float getAmount();

    int date;


};

#endif
