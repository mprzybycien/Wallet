#include "TransactionManager.h"

using namespace std;

void TransactionManager::addNewIncome()
{
    system("cls");
    Income income;
    cout <<">> DODAJ NOWY PRZYCHOD <<" << endl;
    cout <<"_________________________________________________________" << endl;

    income.setId(incomesFile.getLastIncomeId()+1);
    income.setUserId(LOGED_IN_USER_ID);
    income.setDate(todaysOrOtherData());
    income.setAmount(enterAmount());
    income.setTitle(enterIncomeTitle());

    system("cls");
    string fullDate = changeIntDateToFullDate(income.getDate());

    cout << ">> PODSUMOWANIE - PRZYCHOD <<" << endl;
    cout << "_________________________________________________________" << endl;
    cout << "Data: " << fullDate << endl;
    cout << "Kwota: " << std::fixed << setprecision(2) << income.getAmount() << " PLN" << endl;
    cout << "Tytul: " << income.getTitle() << endl;
    cout << "_________________________________________________________" << endl;
    cout << "Kliknij na klawaiturze 't' aby dodac na stale tranakcje lub dowolny inny klawisz aby anulowac" << endl;
    char choice = getch();
    if (choice == 't')
    {
        incomes.push_back(income);
        incomesFile.setLastIncomeId(income.getId());
        incomesFile.appendIncomeToFile(income);
        cout << endl << "Poprawnie dodano nowa transakcje." << endl;
    }
    else
        cout << "Nie dodano transakcji." << endl;
    system("pause");
}

void TransactionManager::addNewExpense()
{
    system("cls");
    Expense expense;
    cout <<">> DODAJ NOWY WYDATEK <<" << endl;
    cout <<"_________________________________________________________" << endl;

    expense.setId(expensesFile.getLastExpenseId()+1);
    expense.setUserId(LOGED_IN_USER_ID);
    expense.setDate(todaysOrOtherData());
    expense.setAmount(enterAmount());
    expense.setTitle(enterExpenseTitle());

    system("cls");
    string fullDate = changeIntDateToFullDate(expense.getDate());

    cout << ">> PODSUMOWANIE - WYDATEK <<" << endl;
    cout << "_________________________________________________________" << endl;
    cout << "Data: " << fullDate << endl;
    cout << "Kwota: " << std::fixed << setprecision(2) << expense.getAmount() << " PLN" << endl;
    cout << "Tytul: " << expense.getTitle() << endl;
    cout << "_________________________________________________________" << endl;
    cout << "Kliknij na klawaiturze 't' aby dodac na stale transakcje lub dowolny inny klawisz aby anulowac" << endl;
    char choice = getch();

    if (choice == 't')
    {
        expenses.push_back(expense);
        expensesFile.setLastExpenseId(expense.getId());
        expensesFile.appendExpenseToFile(expense);
        cout << endl << "Poprawnie dodano nowa transakcje." << endl;
    }
    else
        cout << "Nie dodano transakcji." << endl;
    system("pause");
}

int TransactionManager::todaysOrOtherData()
{
    int choice = 0;
    while(true)
    {
        cout << endl << "1. Transakcja z data dzisiejsza." <<endl;
        cout << "2. Transakcja z inna data." << endl << endl;
        cout << "Wybierz opcje: ";
        cin >> choice;
        if (choice == 1)
        {
            return getActualDateFromSystem();
        }
        else if (choice  == 2)
        {
            return enterDate();
        }
        else
            cout << "Podano niepoprawna wartosc. Sprobuj jeszcze raz." << endl;
    }
}

int TransactionManager::getActualDateFromSystem()
{
    SYSTEMTIME systemDate;
    GetSystemTime(&systemDate);
    string year, month, day, actualDate = "";
    year = GeneralMethods::convertIntToString(systemDate.wYear);
    month = GeneralMethods::convertIntToString(systemDate.wMonth);
    day = GeneralMethods::convertIntToString(systemDate.wDay);

    actualDate = year;

    if ((atoi(month.c_str()) >= 1) && (atoi(month.c_str()) <= 9))
        actualDate = actualDate + "0" + month;
    else
        actualDate = actualDate + month;

    if ((atoi(day.c_str()) >= 1) && (atoi(day.c_str()) <= 9))
        actualDate = actualDate + "0" + day;
    else
        actualDate = actualDate + day;

    return atoi(actualDate.c_str());
}

int TransactionManager::enterDate()
{
    string date;
    while(true)
    {
        cout << endl << "Podaj date w formacie rrrr-mm-dd (na przyklad 2020-04-05): ";
        cin >> date;
        if (isDateInsertCorrectly(date) == true)
            return changeFullDateToIntDate(date);
        else
            cout << "Wprowadzono niepoprawna date. Sprobuj ponownie." << endl;
    }
}

bool TransactionManager::isDateInsertCorrectly (string date)
{
    int year = getYearFromFullDate(date);
    int month = getMonthFromFullDate(date);
    int day = getDayFromFullDate(date);

    if (date.length() != 10)
        return false;
    else if ((date[4] || date[7]) == '-')
        return false;
    else if ((isdigit(date[0])||isdigit(date[1])||
              isdigit(date[2])||isdigit(date[3])||
              isdigit(date[5])||isdigit(date[6])||
              isdigit(date[8])||isdigit(date[9])) == false)
        return false;
    else if ((month < 1) || (month > 12))
        return false;
    else if ((year < 2000) || (changeFullDateToIntDate(date) > getActualDateFromSystem()))
        return false;

    else if (day < 1)
        return false;
    else if ((day > 31) && ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)))
        return false;
    else if ((day > 30) && ((month == 4) || (month == 6) || (month == 9) || (month == 11)))
        return false;
    else if ((day > 29) && (isThisYearLeap(year) == true) && (month == 2))
        return false;
    else if ((day > 28) && (isThisYearLeap(year) == false) && (month == 2))
        return false;
    return true;
}

bool TransactionManager::isThisYearLeap (int year)
{
    if((year%4==0 && year%100!=0) || year%400==0)
        return true;
    else
        return false;
}

int TransactionManager::getYearFromFullDate(string date)
{
    string year;
    for (int i=0; i <= 3; i++)
        year += date[i];
    return atoi(year.c_str());
}

int TransactionManager::getMonthFromFullDate(string date)
{
    string month;
    for (int i=5; i <= 6; i++)
        month += date[i];
    return atoi(month.c_str());
}

int TransactionManager::getDayFromFullDate(string date)
{
    string day;
    for (int i=8; i <= 9; i++)
        day += date[i];
    return atoi(day.c_str());
}

int TransactionManager::changeFullDateToIntDate (string fullDate)
{
    string intDate;
    for (int i=0; i <= fullDate.length(); i ++)
    {
        if (isdigit(fullDate[i]))
            intDate += fullDate[i];
    }
    return atoi(intDate.c_str());
}

string TransactionManager::changeIntDateToFullDate (int date)
{
    string fullDate = GeneralMethods::convertIntToString(date);

    fullDate.insert(4, "-");
    fullDate.insert(7, "-");

    return fullDate;
}

float TransactionManager::enterAmount()
{
    string amount;
    float floatAmount;
    while (true)
    {
        cout << endl << "Podaj kwote transakcji (jako separatora uzyj kropki lub przecinka): ";
        cin >> amount;
        if (isAmountInsertCorrectly(amount))
        {
            return replaceCommaToDotInAmount(amount);
        }
        else
            cout << "Wprowadzono niepoprawna kwote. Sprobuj ponownie." << endl;
    }
}

bool TransactionManager::isAmountInsertCorrectly (string date)
{
    int separatorCounter = 0;
    for (int i = 0; i < date.length(); i++)
    {
        if ((date[i] == '.') || (date[i] == ','))
        {
            separatorCounter++;
            if (separatorCounter > 1)
                return false;
        }

        else if ((isdigit(date [i]) || ((date[i] == '.')) || ((date[i] == ','))) == false)
            return false;
    }
    return true;
}

float TransactionManager::replaceCommaToDotInAmount(string amount)
{
    float amountFloat;
    for (int i = 0; i <= amount.length(); i++)
    {
        if (amount[i] == ',')
            amount.replace(i,1,".");
    }
    amountFloat = atof(amount.c_str());
    return amountFloat;
}

string TransactionManager::enterIncomeTitle()
{
    string title;
    int choice;
    while(true)
    {
        cout << endl << "Wybierz tytul transakcji: " << endl;
        cout << "1. Wyplata." << endl;
        cout << "2. Fuszka." << endl;
        cout << "3. Darowizna." << endl;
        cout << "4. Zwrot." << endl;
        cout << "5. Podaj inny tytul." << endl;
        cout << "______________________" << endl;
        cout << "Wybierz opcje : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            return "Wyplata";
            break;
        case 2:
            return "Fuszka";
            break;
        case 3:
            return "Darowizna";
            break;
        case 4:
            return "Zwrot";
            break;
        case 5:
            cout << "Podaj inny tytul transakcji: ";
            return title = GeneralMethods::insertTextLine();
            break;
        default:
            cout << "Podano niewlasciwa wartosc. Sprobuj jeszcze raz." <<endl;
            break;
        }
    }
}

string TransactionManager::enterExpenseTitle()
{
    while(true)
    {
        string title;
        int choice;
        cout << endl << "Wybierz tytul transakcji: " << endl;
        cout << "1. Rata kredytu." << endl;
        cout << "2. Czynsz." << endl;
        cout << "3. Zakupy spozywcze." << endl;
        cout << "4. Zakupy bez sensu." << endl;
        cout << "5. Podaj inny tytul." << endl;
        cout << "______________________" << endl;
        cout << "Wybierz opcje : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            return "Rata kredytu";
            break;
        case 2:
            return "Czynsz";
            break;
        case 3:
            return "Zakupy spozywcze";
            break;
        case 4:
            return "Zakupy bez sensu";
            break;
        case 5:
            cout << "Podaj inny tytul transakcji: ";
            return title = GeneralMethods::insertTextLine();
            break;
        default:
            cout << "Podano niewlasciwa wartosc. Sprobuj jeszcze raz." <<endl;
            break;
        }
    }
}

void TransactionManager::showIncomesDetailsOfLogInUserSortedByDate(vector <Transaction> &tempIncomes )
{
    Transaction transaction;
    tempIncomes = transaction.sortLogedInUserTransactions(tempIncomes);

    cout << " ________________________________________________" << endl;
    cout << " >> Przychody wg daty <<" << endl;
    cout << " ________________________________________________" << endl;

    for (vector<Transaction>::iterator itr = tempIncomes.begin(); itr != tempIncomes.end(); itr++)
    {
        cout << "__" << endl;
        cout << "Data: " << changeIntDateToFullDate(itr -> getDate()) << endl;
        cout << "Tytul: " << itr -> getTitle() << endl;
        cout << "Kwota: " << std::fixed << setprecision(2) <<  itr -> getAmount() << " PLN" << endl;
    }
}

void TransactionManager::showExpensesDetailsOfLogInUserSortedByDate(vector <Transaction> &tempExpenses)
{
    Transaction transaction;
    tempExpenses = transaction.sortLogedInUserTransactions(tempExpenses);

    cout << " ________________________________________________" << endl;
    cout << " >> Wydatki wg daty <<" << endl;
    cout << " ________________________________________________" << endl;

    for (vector<Transaction>::iterator itr = tempExpenses.begin(); itr != tempExpenses.end(); itr++)
    {
        cout << "__" << endl;
        cout << "Data: " << changeIntDateToFullDate(itr -> getDate()) << endl;
        cout << "Tytul: " << itr -> getTitle() << endl;
        cout << "Kwota: " << std::fixed << setprecision(2) <<  itr -> getAmount() << " PLN" << endl;
    }
}

vector <Transaction> TransactionManager::writeIncomesFromSpecifiedPeriodToTempVector(int earlyDate, int lateDate)
{
    vector <Transaction> tempIncomes;
    Income income;

    for (int i=0; i <incomes.size(); i++)
    {
        if ((incomes[i].getDate() >= earlyDate) && (incomes[i].getDate() <= lateDate))
        tempIncomes.push_back(incomes[i]);
    }
    return tempIncomes;
}

vector <Transaction> TransactionManager::writeExpensesFromSpecifiedPeriodToTempVector(int earlyDate, int lateDate)
{
    vector <Transaction> tempExpenses;
    Expense expense;

    for (int i=0; i <expenses.size(); i++)
    {
        if ((expenses[i].getDate() >= earlyDate) && (expenses[i].getDate() <= lateDate))
        tempExpenses.push_back(expenses[i]);
    }
    return tempExpenses;
}

void TransactionManager::showSumOfTransactions(vector <Transaction> tempIncomes, vector <Transaction> tempExpenses)
{
    float sumOfIncomes = 0, sumOfExpenses = 0;
    for (vector<Transaction>::iterator itr = tempIncomes.begin(); itr != tempIncomes.end(); itr++)
        sumOfIncomes += itr -> getAmount();

    for (vector<Transaction>::iterator itr = tempExpenses.begin(); itr != tempExpenses.end(); itr++)
        sumOfExpenses -= itr -> getAmount();
    cout << "Suma przychodow: " << sumOfIncomes << std::fixed << setprecision(2) << "PLN" << endl;
    cout << "Suma wydatkow: " << sumOfExpenses << std::fixed << setprecision(2) << "PLN" << endl;
}

void TransactionManager::showCurrentMonthBalance()
{
    string date = changeIntDateToFullDate(getActualDateFromSystem());
    date.replace(8,2,"01");

    int earlyDate = changeFullDateToIntDate(date);
    int lateDate = getActualDateFromSystem();

    vector <Transaction> tempIncomes = writeIncomesFromSpecifiedPeriodToTempVector(earlyDate, lateDate);
    vector <Transaction> tempExpenses = writeExpensesFromSpecifiedPeriodToTempVector(earlyDate, lateDate);

    system ("cls");
    cout << "Suma transakcji z bierzacego miesiaca: " << endl << endl;
    showSumOfTransactions(tempIncomes, tempExpenses);
    showIncomesDetailsOfLogInUserSortedByDate(tempIncomes);
    showExpensesDetailsOfLogInUserSortedByDate(tempExpenses);
    system("pause");
}

void TransactionManager::showPreviousMonthBalance()
{
    string date;

    int month = getMonthFromFullDate(changeIntDateToFullDate(getActualDateFromSystem()));
    int earlyDate, lateDate;

    if (month == 1)
        date = changeIntDateToFullDate(getActualDateFromSystem() - 8900);
    else
        date = changeIntDateToFullDate(getActualDateFromSystem() - 100); // Magiczne liczby 8900 oraz 100 :D

    date.replace(8,2,"01");

    earlyDate = changeFullDateToIntDate(date);

    month = getMonthFromFullDate(date);
    int year = getYearFromFullDate(date);

    if ((month == 1) ||
       (month == 3) ||
       (month == 5) ||
       (month == 7) ||
       (month == 8) ||
       (month == 10) ||
       (month == 12))
       date.replace(8,2,"31");
    else if ((month == 4) ||
             (month == 6) ||
             (month == 9) ||
             (month == 11))
        date.replace(8,2,"30");
    else if ((month == 2) && (isThisYearLeap(year) == true))
        date.replace(8,2,"29");
    else if ((month == 2) && (isThisYearLeap(year) == false))
        date.replace(8,2,"28");

    lateDate = changeFullDateToIntDate(date);

    vector <Transaction> tempIncomes = writeIncomesFromSpecifiedPeriodToTempVector(earlyDate, lateDate);
    vector <Transaction> tempExpenses = writeExpensesFromSpecifiedPeriodToTempVector(earlyDate, lateDate);

    system ("cls");
    cout << "Suma transakcji z poprzedniego miesiaca: " << endl << endl;
    showSumOfTransactions(tempIncomes, tempExpenses);
    showIncomesDetailsOfLogInUserSortedByDate(tempIncomes);
    showExpensesDetailsOfLogInUserSortedByDate(tempExpenses);
    system ("pause");
}

void TransactionManager::showSelectedPeroidBalance()
{
    int earlyDate, lateDate;

    cout << endl << ">> DATA POCZATKOWA <<";
    earlyDate = enterDate();

    cout << endl << ">> DATA KONCOWA <<";
    lateDate = enterDate();

    vector <Transaction> tempIncomes = writeIncomesFromSpecifiedPeriodToTempVector(earlyDate, lateDate);
    vector <Transaction> tempExpenses = writeExpensesFromSpecifiedPeriodToTempVector(earlyDate, lateDate);

    system ("cls");
    cout << "Suma transakcji z przedzialu od " << changeIntDateToFullDate(earlyDate) << " do " << changeIntDateToFullDate(lateDate) << ":" << endl << endl;
    showSumOfTransactions(tempIncomes, tempExpenses);
    showIncomesDetailsOfLogInUserSortedByDate(tempIncomes);
    showExpensesDetailsOfLogInUserSortedByDate(tempExpenses);
    system ("pause");
}


