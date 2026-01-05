#pragma once
#include <iostream>
#include <iomanip>
#include "clsWork.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsWorkRegisterScreen.h"


class clsAddNewWork : protected clsScreen
{
private:

	static void _ReadWorkInfo(clsWork& Work)
	{
		cout << "\nEnter Work Number: ";
		Work.WorkNumber() = clsInputValidate::ReadString();

		cout << "\nEnter Work Name: ";
		Work.WorkName = clsInputValidate::ReadString();

		cout << "\nEnter Work Description: ";
		Work.WorkDescription = clsInputValidate::ReadString();
	}

	static void _PrintWork(clsWork Work)
	{
		cout << "\nWork Info:";
		cout << "\n____________________________________________";
		cout << "\nWork ID         : " << Work.WorkNumber();
		cout << "\nWork Name       : " << Work.WorkName;
		cout << "\nWork Description: " << Work.WorkDescription;
		cout << "\nWork Date/Time  : " << Work.GetCreationDateTime();
		cout << "\nWork Status     : " << (Work.WorkStatus ? "Yes" : "No");
		cout << "\n____________________________________________";
	}

public:

	static void ShowAddNewWorkScreen()
	{
		_DrawScreenHeader("\t   Add New Work Screen");

		string WorkNumber = "";

		cout << "\nPlease Enter Work Number: ";
		WorkNumber = clsInputValidate::ReadString();

		while (clsWork::IsWorkExist(WorkNumber))
		{
			cout << "\nWork Number Is Already Used, Choose another one: ";
			WorkNumber = clsInputValidate::ReadString();
		}

		clsWork NewWork = clsWork::GetAddNewWorkObject(WorkNumber);

		_ReadWorkInfo(NewWork);

		clsWork::enSaveResults SaveResult;

		SaveResult = NewWork.Save();

		switch (SaveResult)
		{
			case clsWork::enSaveResults::svSucceeded:
			{
				cout << "\nWork Added Successfull :)\n";
				_PrintWork(NewWork);
				break;
			}
			
			case clsWork::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nError work was not saved because it's empty";
				break;
			}
			case clsWork::enSaveResults::svFaildWorkNumberExists:
			{
				cout << "\nError work was not saved because work number is used!\n";
				break;
			}
		}
	}
};

