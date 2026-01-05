#pragma once
#include <iostream>
#include <iomanip>
#include "clsWork.h"
#include "clsScreen.h"

class clsWorkRegisterScreen : protected clsScreen
{
private:
	
	static void _PrintWorkRegisterRecordLine(clsWork::stWorkRegisterRecord WorkRegisterRecord)
	{
		//cout << setw(8) << left << "" << "| " << setw(8) << left << WorkRegisterRecord.WorkDate;
		//cout << "| " << setw(20) << left << WorkRegisterRecord.WorkNumber;
		//cout << "| " << setw(20) << left << WorkRegisterRecord.WorkName;
		//cout << "| " << setw(10) << left << WorkRegisterRecord.WorkStatus;


		short wID = 8;
		short wName = 30;
		short wDate = 22;
		short wStatus = 5;

		string FullName = WorkRegisterRecord.WorkName;
		short NameLength = FullName.length();

		if (NameLength == 0)
			FullName = "";

		for (short i = 0; i < FullName.length(); i += wName)
		{
			string Segment = FullName.substr(i, wName);

			cout << setw(8) << left << "";

			if (i == 0)
			{
				cout << "| " << setw(wDate) << left << WorkRegisterRecord.WorkDate;
				cout << "| " << setw(wID) << left << WorkRegisterRecord.WorkNumber;

				cout << "| " << setw(wName) << left << Segment;

				cout << "| " << setw(wStatus) << left << (WorkRegisterRecord.WorkStatus ? "Yes" : "No");
			}

			else
			{
				cout << "| " << setw(wDate) << left << "";
				cout << "| " << setw(wID) << left << "";

				cout << "| " << setw(wName) << left << Segment;
				cout << "| " << setw(wStatus) << left << "";

			}

			cout << endl;
		}
	}

public:

	static void ShowWorkRegisterScreen()
	{
		vector <clsWork::stWorkRegisterRecord> vWorkRegisterRecord = clsWork::GetWorkRegisterRecord();

		string Title = "\tWork Register List Screen";
		string SubTitle = "\t\t(" + to_string(vWorkRegisterRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "____________________________________________________\n" << endl;

		cout << "\t| " << left << setw(22) << "Work Date";
		cout << "| " << left << setw(8) << "Work ID";
		cout << "| " << left << setw(30) << "Work Name";
		cout << "| " << left << setw(5) << "Status";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "____________________________________________________\n" << endl;

		if (vWorkRegisterRecord.size() == 0)
			cout << "\t\t\t\tNo Works Avaliable In the system!";

		else

			for (clsWork::stWorkRegisterRecord Record : vWorkRegisterRecord)
			{
				_PrintWorkRegisterRecordLine(Record);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "____________________________________________________\n" << endl;
	}
};

