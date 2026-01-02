#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "clsManageUsersMenu.h"
#include "Global.h"
#include "clsDate.h"
using namespace std;

class clsLoginScreen :protected clsScreen
{

private:

    static void _Login()
    {
        bool LoginFaild = false;
        int attempts = 0;

        string Username, Password;

        do
        {
            if (LoginFaild)
            {
                attempts++;
                cout << "\nInvalid Username/Password!\n";
                cout << "Attempts left: " << (3 - attempts) << "\n\n";
            }

            if (attempts >= 3)
            {
                cout << "\n====================================\n";
                cout << " SYSTEM LOCKED\n";
                cout << " Too many failed login attempts.\n";
                cout << " Please contact the administrator.\n";
                cout << "====================================\n";
                exit(0);   // Stops the program completely
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);
            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        // Successful login only
        cout << "\n";
        cout << setw(12) << left << "User:" << CurrentUser.FullName() << "\n";
        cout << setw(12) << left << "Date:" << clsDate::GetSystemDate().DateToString() << "\n\n";

        clsMainScreen::ShowMainMenue();
    }

public:


    static void ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
      
        _Login();

    }

};

