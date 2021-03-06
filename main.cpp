#include <iostream>
#include "MyFinances.h"

using namespace std;

int main()
{
    MyFinances myFinances ("Users.xml", "Incomes.xml", "Expenses.xml");
    int choice;
    while(true)
    {
        system("cls");
        cout << "Menu logowania" << endl;
        cout << "_______________________" << endl;
        cout << "1. Zarejestruj sie" << endl;
        cout << "2. Zaloguj sie" << endl;
        cout << "9. Zakoncz program" <<endl;
        cout << "_______________________" << endl;
        cout << "Wybierz opcje:" << endl;
        cin >> choice;
        switch(choice)
        {
        case 1:
            myFinances.registration();
            break;
        case 2:
            myFinances.logIn();
            while (myFinances.isUserLogedIn() == true)
            {
                string dataOfLogInUser = myFinances.showDataOfLogInUser();
                system("cls");
                cout << "PULPIT UZYTKOWNIKA: " << dataOfLogInUser << endl;
                cout << "_______________________" << endl;
                cout << "1. Dodaj przychod." << endl;
                cout << "2. Dodaj wydatek" << endl;
                cout << "3. Pokaz zestawienie transakcji z bierzacego miesiaca" << endl;
                cout << "4. Pokaz zestawienie transakcji z poprzedniego miesiaca" << endl;
                cout << "5. Pokaz zestawienie transakcji ze wskazanego okresu" << endl;
                cout << "6. Zmien haslo" << endl;
                cout << "9. Wyloguj sie" <<endl;
                cout << "_______________________" << endl;
                cout << "Wybierz opcje:" << endl;
                cin >> choice;
                switch(choice)
                {
                case 1:
                    myFinances.addNewIncome();
                    break;
                case 2:
                    myFinances.addNewExpense();
                    break;
                case 3:
                    myFinances.showCurrentMonthBalance();
                    break;
                case 4:
                    myFinances.showPreviousMonthBalance();
                    break;
                case 5:
                    myFinances.showSelectedPeroidBalance();
                    break;
                case 6:
                    myFinances.changePassword();
                    break;
                case 9:
                    myFinances.logOut();
                    break;
                }
            }
            break;
        case 9:
            exit(0);
        }
    }
    return 0;
}
