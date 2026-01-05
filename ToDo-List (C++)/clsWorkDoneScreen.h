#pragma once
#include <iostream>
#include <iomanip>
#include "clsWork.h"
#include "clsScreen.h"

class clsWorkDoneScreen : protected clsScreen
{
private:

	static void _PrintWorkRecordLine(clsWork Work)
	{
		//cout << setw(8) << left << "" << "| " << setw(8) << left << Work.WorkNumber;
		//cout << "| " << setw(20) << left << Work.WorkName;
		//cout << "| " << setw(40) << left << Work.WorkDescription;
		//cout << "| " << setw(20) << left << Work.GetCreationDateTime();
		//cout << "| " << setw(10) << left << Work.WorkDone;

		short wID = 8;
		short wName = 20;
		short wDesc = 40;
		short wDate = 20;
		short wStatus = 10;

		string FullDescription = Work.WorkDescription;
		short DescLength = FullDescription.length();

		if (DescLength == 0)
			FullDescription = "";

		for (short i = 0; i < FullDescription.length(); i += wDesc)
		{
			string Segment = FullDescription.substr(i, wDesc);

			cout << setw(8) << left << "";

			if (i == 0)
			{
				cout << "| " << setw(wID) << left << Work.WorkNumber();

				if (Work.WorkName.length() > wName)
					cout << "| " << setw(wName) << left << (Work.WorkName.substr(0, wName - 3) + "..");
				else
					cout << "| " << setw(wName) << left << Work.WorkName;

				cout << "| " << setw(wDesc) << left << Segment;

				cout << "| " << setw(wDate) << left << Work.GetCreationDateTime();
				cout << "| " << setw(wStatus) << left << (Work.WorkStatus ? "Yes" : "No");
			}

			else
			{
				cout << "| " << setw(wID) << left << "";
				cout << "| " << setw(wName) << left << "";

				cout << "| " << setw(wDesc) << left << Segment;

				cout << "| " << setw(wDate) << left << "";
				cout << "| " << setw(wStatus) << left << "";
			}

			cout << endl;

		}
	}

public:

	static void ShowWorkDoneScreen()
	{
		vector<clsWork> vWorks = clsWork::GetWorksList();
		
		vector<clsWork> vCompletedWorks;

		for (clsWork& W : vWorks)
		{
			if (W.WorkStatus)
			{
				vCompletedWorks.push_back(W);
			}
		}

		string Title = "\t  Completed Work Screen";
		string SubTitle = "\t Total Completed (" + to_string(vCompletedWorks.size()) + ") Work(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "____________________________________________________\n" << endl;

		cout << "\t| " << left << setw(8) << "Work ID";
		cout << "| " << left << setw(20) << "Work Name";
		cout << "| " << left << setw(40) << "Work Des.";
		cout << "| " << left << setw(20) << "Date/Time";
		cout << "| " << left << setw(10) << "Status";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "____________________________________________________\n" << endl;

		//cout << "\n\t" << string(100, '_') << "\n";

		if (vCompletedWorks.size() == 0)
			cout << "\t\t\t\tNo Completed Works Yet!";

		else

			for (clsWork &Work : vCompletedWorks)
			{
				_PrintWorkRecordLine(Work);
				cout << setw(8) << left << "" << string(102, '_') << " |" << "\n";
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "____________________________________________________\n" << endl;
	}
};

