#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsWorkListScreen.h"
#include "clsAddNewWork.h"
#include "clsDeleteWorkScreen.h"
#include "clsFindWorkScreen.h"
#include "clsWorkRegisterScreen.h"
#include "clsUpdateMainScreen.h"
#include "clsWorkDoneScreen.h"

using namespace std;

class clsMainScreen :protected clsScreen
{

private:
    enum enMainMenueOptions {
        eListWorks = 1, eAddNewWork = 2, eDeleteWork = 3,
        eUpdateWork = 4, eFindWork = 5, eWorkRegister = 6, eWorkDone = 7, eExit = 8
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 8, "Enter Number Between 1 to 8? ");
        return Choice;
    }

    static void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllWorksScreen()
    {
        /*cout << "\nWork List Screen will be here...\n";*/
        clsWorkListScreen::ShowWorkList();
    }

    static void _ShowAddNewWorkScreen()
    {
        /*cout << "\nAdd New Work Screen will be here...\n";*/
        clsAddNewWork::ShowAddNewWorkScreen();
    }

    static void _ShowDeleteWorkScreen()
    {
        /*cout << "\nDelete Work Screen will be here...\n";*/
        clsDeleteWorkScreen::ShowDeleteWorkScreen();
    }

    static void _ShowUpdateWorkScreen()
    {
        /*cout << "\nUpdate Work Screen will be here...\n";*/
        clsUpdateMainScreen::ShowUpdateMenue();
    }

    static void _ShowFindWorkScreen()
    {
        /*cout << "\nFind Work Screen will be here...\n";*/
        clsFindWorkScreen::ShowFindWorkScreen();
    }


    static void _ShowWorkRegister()
    {
        /*cout << "\n Work Register Screen will be here...\n"; */
        clsWorkRegisterScreen::ShowWorkRegisterScreen();
    }

    static void _ShowWorkDone()
    {
        /*cout << "\nWork Done Screen Will be here soon...\n";*/
        clsWorkDoneScreen::ShowWorkDoneScreen();
    }


    static void _PerformMainMenueOption(enMainMenueOptions MainMenuOption)
    {
        switch (MainMenuOption)
        {
            case enMainMenueOptions::eListWorks:
            {
                system("cls");
                _ShowAllWorksScreen();
                _GoBackToMainMenue();
                break;
            }

            case enMainMenueOptions::eAddNewWork:
            {
                system("cls");
               _ShowAddNewWorkScreen();
               _GoBackToMainMenue();
                break;
            }

            case enMainMenueOptions::eDeleteWork:
            {
                system("cls");
               _ShowDeleteWorkScreen();
                _GoBackToMainMenue();
                break;
            }

            case enMainMenueOptions::eUpdateWork:
            {
                system("cls");
                _ShowUpdateWorkScreen();
                _GoBackToMainMenue();
                break;
            }

            case enMainMenueOptions::eFindWork:
            {
                system("cls");
                _ShowFindWorkScreen();
                _GoBackToMainMenue();
                break;
            }

            case enMainMenueOptions::eWorkRegister:
            {
                system("cls");
                _ShowWorkRegister();
                _GoBackToMainMenue();
                break;
            }

            case enMainMenueOptions::eWorkDone:
            {
                system("cls");
                _ShowWorkDone();
                _GoBackToMainMenue();
                break;
            }

            case enMainMenueOptions::eExit:
            {
                exit(0);
                break;
            }

        }
    }

public:

    static  void ShowMainMenue()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show To-Do List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Work.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Work.\n";
        cout << setw(37) << left << "" << "\t[4] Update Work Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Work In List.\n";
        cout << setw(37) << left << "" << "\t[6] Work Register.\n";
        cout << setw(37) << left << "" << "\t[7] Work Done.\n";
        cout << setw(37) << left << "" << "\t[8] Exit.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};

