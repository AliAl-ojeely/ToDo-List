#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUpdateWorkInfoScreen.h"
#include "clsUpdateWorkStatus.h"

using namespace std;

class clsUpdateMainScreen : protected clsScreen
{
    enum enUpdateMainMenueOptions {
        eUpdateWorkInfo = 1, eUpdateStatus = 2, eShowMainMenue = 3
    };

    static short _ReadUpdateMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 3]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 3, "Enter Number Between 1 to 3? ");
        return Choice;
    }

    static void _ShowUpdateWorkInfoScreen()
    {
        /*cout << "\nUpdate Work Info Screen Will be here soon...\n";*/
        clsUpdateWorkInfoScreen::ShowUpdateWorkInfoScreen();
    }

    static void _ShowUpdateWorkStatusScreen()
    {
        /*cout << "\nUpdate Work Status Screen Will be here soon...\n";*/
        clsUpdateWorkStatus::ShowUpdateWorkStatusScreen();
    }

    static void _GoBackToUpdateMenue()
    {
        cout << "\n\nPress any key to go back to Update Menue...";
        system("pause>0");
        ShowUpdateMenue();
    }

    static void _PerformUpdateMenueOptions(enUpdateMainMenueOptions UpdateMainMenueOptions)
    {
        switch (UpdateMainMenueOptions)
        {
            case enUpdateMainMenueOptions::eUpdateWorkInfo:
            {
                system("cls");
                _ShowUpdateWorkInfoScreen();
                _GoBackToUpdateMenue();
                break;
            }

            case enUpdateMainMenueOptions::eUpdateStatus:
            {
                system("cls");
                _ShowUpdateWorkStatusScreen();
                _GoBackToUpdateMenue();
                break;
            }

            case enUpdateMainMenueOptions::eShowMainMenue:
            {
                // Do Nothing Here The Main Screen Will Handle it :) ;
            }
        }
    }

public:

    static void ShowUpdateMenue()
    {
        system("cls");
        _DrawScreenHeader("\t  Update Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Update Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Update Work Info.\n";
        cout << setw(37) << left << "" << "\t[2] Update Work Status.\n";
        cout << setw(37) << left << "" << "\t[3] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformUpdateMenueOptions((enUpdateMainMenueOptions)_ReadUpdateMainMenueOption());
    }
};

