#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "Expense.h"
#include "Income.h"
#include "GeneralMethods.h"

using namespace std;

class TransactionManager
{
    //const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    //PlikZAdresatami plikZAdresatami;
    vector <Income> incomes;
    vector <Expense> expenses;


public:
    /*AdresatManager (string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) :
        plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        incomes = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    */
    void addNewIncome();
    void addNewExpanse();
};

#endif

