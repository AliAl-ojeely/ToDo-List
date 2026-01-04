#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsWork.h"
#include "clsInputValidate.h"

class clsDeleteWorkScreen : protected clsScreen
{
private:
	
	static void _PrintWork(clsWork Work)
	{
		cout << "\nWork Info:";
		cout << "\n___________________________________________";
		cout << "\nWork Number      : " << Work.WorkNumber;
		cout << "\nWork Name        : " << Work.WorkName;
		cout << "\nWork Description : " << Work.WorkDescription;
		cout << "\nWork Date/Time   : " << Work.GetCreationDateTime();
		cout << "\nWork Status      : " << Work.WorkStatus;
		cout << "\n___________________________________________";
	}

public:

	static void ShowDeleteWorkScreen()
	{
		_DrawScreenHeader("\tDelete Work Screen");

		string WorkNumber = "";

		cout << "\nPlease Enter Work Number: ";
		WorkNumber = clsInputValidate::ReadString();

		while (!clsWork::IsWorkExist(WorkNumber))
		{
			cout << "\nWork Number is not found, choose another one: ";
			WorkNumber = clsInputValidate::ReadString();
		}

		clsWork Work1 = clsWork::Find(WorkNumber);
		_PrintWork(Work1);

		cout << "\nAre you sure you want to delete this work y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Work1.Delete())
			{
				cout << "\nClient Deleted Successfully :)\n";
				_PrintWork(Work1);
			}
			else
			{
				cout << "\nError Client was not Deleted\n";
			}
		}

	}
};

