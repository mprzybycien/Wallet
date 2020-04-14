#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <windows.h>
#include "Expense.h"
#include "Income.h"
#include "Transaction.h"
#include "GeneralMethods.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"

using namespace std;

class TransactionManager
{
    const int LOGED_IN_USER_ID;

    IncomesFile incomesFile;
    ExpensesFile expensesFile;

    vector <Income> incomes;
    vector <Expense> expenses;

    int todaysOrOtherData();
    int getActualDateFromSystem();
    int enterDate();
    bool isDateInsertCorrectly (string date);
    bool isThisYearLeap (int year);
    int getYearFromFullDate(string date);
    int getMonthFromFullDate(string date);
    int getDayFromFullDate(string date);
    int changeFullDateToIntDate (string fullDate);
    string changeIntDateToFullDate (int date);
    float enterAmount();
    bool isAmountInsertCorrectly (string date);
    float roundAmount (float amount);
    float replaceCommaToDotInAmount(string amount);
    string enterIncomeTitle();
    string enterExpenseTitle();
    void showIncomesDetailsOfLogInUserSortedByDate(vector <Transaction> &tempIncomes);
    void showExpensesDetailsOfLogInUserSortedByDate(vector <Transaction> &tempExpenses);
    vector <Transaction> writeIncomesFromSpecifiedPeriodToTempVector(int earlyDate, int lateDate);
    vector <Transaction> writeExpensesFromSpecifiedPeriodToTempVector(int earlyDate, int lateDate);

public:
    TransactionManager (int logedInUserId) : LOGED_IN_USER_ID(logedInUserId)
    {
        incomes = incomesFile.loadLogedInUserIncomes(LOGED_IN_USER_ID);
        expenses = expensesFile.loadLogedInUserExpenses(LOGED_IN_USER_ID);
    };

    void addNewIncome();
    void addNewExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showSelectedPeroidBalance();
};

#endif

