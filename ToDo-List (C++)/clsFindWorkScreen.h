#pragma once
#include <iostream>
#include "clsWork.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsFindWorkScreen : protected clsScreen
{
private:

	static void _PrintWork(clsWork Work)
	{
		cout << "\nWork Info:";
		cout << "\n___________________________________________";
		cout << "\nWork Number      : " << Work.WorkNumber();
		cout << "\nWork Name        : " << Work.WorkName;
		cout << "\nWork Description : " << Work.WorkDescription;
		cout << "\nWork Date/Time   : " << Work.GetCreationDateTime();
		cout << "\nWork Status      : " << (Work.WorkStatus ? "Yes" : "No");
		cout << "\n___________________________________________";
	}

public:
	
	static void ShowFindWorkScreen()
	{

		_DrawScreenHeader("\tFind Work Screen");

		string WorkNumber = "";

		cout << "\nPlease Enter Work Number: ";
		WorkNumber = clsInputValidate::ReadString();

		while (!clsWork::IsWorkExist(WorkNumber))
		{
			cout << "\nWork Number is not found, choose another one: ";
			WorkNumber = clsInputValidate::ReadString();
		}

		clsWork Work1 = clsWork::Find(WorkNumber);

		if (!Work1.IsEmpty())
		{
			cout << "\nWork Found :)\n";
		}
		else
		{
			cout << "\nWork was not found :(\n";
		}

		_PrintWork(Work1);
	}
};

