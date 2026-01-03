#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsWorkManager.h"

class clsWorkListScreen : protected clsScreen
{
private:

	static void _PrintWorkRecordLine(clsWork Work)
	{
		cout << setw(8) << left << "" << "| " << setw(8) << left << Work.WorkNumber;
		cout << "| " << setw(20) << left << Work.WorkName;
		cout << "| " << setw(39) << left << Work.WorkDescription;
		cout << "| " << setw(20) << left << Work.GetCreationDateTime();
		cout << "| " << setw(7) << left << Work.WorkDone;
	}

public:

	static void ShowWorkList()
	{
		vector<clsWork> vWorks = clsWorkManager::GetWorksList();
		string Title = "\t  Work List Screen";
		string SubTitle = "\t   (" + to_string(vWorks.size()) + ") Work(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "____________________________________________________\n" << endl;

		cout << "\t| " << left << setw(8) << "Work ID";   
		cout << "| " << left << setw(20) << "Work Name";      
		cout << "| " << left << setw(40) << "Work Des.";
		cout << "| " << left << setw(19) << "Date/Time";     
		cout << "| " << left << setw(11) << "Status";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "____________________________________________________\n" << endl;

		//cout << "\n\t" << string(100, '_') << "\n";

		if (vWorks.size() == 0)
			cout << "\t\t\t\tNo Works Available In the System";

		else

			for (clsWork Work : vWorks)
			{
				_PrintWorkRecordLine(Work);
				cout << endl;
			}


		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "____________________________________________________\n" << endl;
	}
};

