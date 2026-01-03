#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsString.h"
#include "clsDate.h"
#include "clsWork.h"

using namespace std;

class clsWorkManager
{
private:
	//enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	//enMode _Mode;
	//bool _MarkedForDelete = false;

	static clsWork _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vWorkData;
		vWorkData = clsString::Split(Line, Seperator);

		return clsWork(
			vWorkData[0],                 // WorkNumber
			vWorkData[1],                 // WorkName
			vWorkData[2],                 // WorkDescription
			vWorkData[3],                 // CreationDateTime
			stoi(vWorkData[4])			  // WorkDone
		);
	}

	static string _ConvertWorkObjectToLine(clsWork Work, string Seperator = "#//#")
	{
		string stWorkRecord = "";

		stWorkRecord += Work.WorkNumber + Seperator;
		stWorkRecord += Work.WorkName + Seperator;
		stWorkRecord += Work.WorkDescription + Seperator;
		stWorkRecord += Work.GetCreationDateTime() + Seperator;
		stWorkRecord += to_string(Work.WorkDone);

		return stWorkRecord;

	}

	static vector<clsWork> _LoadWorksDataFromFile()
	{
		vector <clsWork> vWorks;

		fstream MyFile;
		MyFile.open("To-DoList.txt", ios::in); // Read Only

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				if (Line != "")
				{
					clsWork Work = _ConvertLineToClientObject(Line);
					vWorks.push_back(Work);
				}
			}
			MyFile.close();
		}

		return vWorks;
	}

public:
	

	static vector <clsWork> GetWorksList()
	{
		return _LoadWorksDataFromFile();
	}
	
};

