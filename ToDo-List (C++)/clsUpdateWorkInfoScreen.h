#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsWork.h"
#include "clsInputValidate.h"

class clsUpdateWorkInfoScreen : protected clsScreen
{
private:

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

	static void _ReadWorkInfo(clsWork& Work)
	{
		cout << "\nEnter Work Name: ";
		Work.WorkName = clsInputValidate::ReadString();

		cout << "\nEnter Work Description: ";
		Work.WorkDescription = clsInputValidate::ReadString();
	}

public:

	static void ShowUpdateWorkInfoScreen()
	{

		_DrawScreenHeader("\tUpdate Work Info");

		string WorkNumber = "";

		cout << "\nPlease Enter Work Number: ";
		WorkNumber = clsInputValidate::ReadString();

		while (!clsWork::IsWorkExist(WorkNumber))
		{
			cout << "\nWork Number Is Not found, Choose another one: ";
			WorkNumber = clsInputValidate::ReadString();
		}

		clsWork Work1 = clsWork::Find(WorkNumber);

		_PrintWork(Work1);

		cout << "\n\nAre you surer you want to update this Work Info y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n\nUpdate Work Info:";

			_ReadWorkInfo(Work1);

			clsWork::enSaveResults SaveResult;

			SaveResult = Work1.Save();

			switch (SaveResult)
			{
				case clsWork::enSaveResults::svSucceeded:
				{
					cout << "\nWork Updated Successfully :)\n";

					_PrintWork(Work1);
					break;
				}
				case clsWork::enSaveResults::svFaildEmptyObject:
				{
					cout << "\nError Work Was not Saved beacause it's Empty";
					break;
				}
			}
		}




	}

};

