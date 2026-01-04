#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsString.h"
#include "clsDate.h"

using namespace std;

class clsWork
{
private:

	bool _MarkedForDelete = false;

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _WorkNumber;
	string _WorkName;
	string _WorkDescription;
	string _CreationDateTime;
	bool _WorkStatus = 0;

	static clsWork _ConvertLineToWorkObject(string Line, string Seperator = "#//#")
	{
		vector<string> vWorkData;
		vWorkData = clsString::Split(Line, Seperator);

		return clsWork(
			enMode::UpdateMode,			  // Mode
			vWorkData[0],                 // WorkNumber
			vWorkData[1],                 // WorkName
			vWorkData[2],                 // WorkDescription
			vWorkData[3],                 // CreationDateTime
			stoi(vWorkData[4])			  // WorkStatus
		);
	}

	static string _ConvertWorkObjectToLine(clsWork Work, string Seperator = "#//#")
	{
		string stWorkRecord = "";

		stWorkRecord += Work.WorkNumber + Seperator;
		stWorkRecord += Work.WorkName + Seperator;
		stWorkRecord += Work.WorkDescription + Seperator;
		stWorkRecord += Work.GetCreationDateTime() + Seperator;
		stWorkRecord += to_string(Work.WorkStatus);

		return stWorkRecord;
	}

	static clsWork _GetEmptyWorkObject()
	{
		return clsWork(enMode::EmptyMode, "", "", "", "", false);
	}

	static vector<clsWork> _LoadWorksDataFromFile()
	{
		vector <clsWork> vWorks;

		fstream MyFile;
		MyFile.open("ToDoList.txt", ios::in); // Read Only

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				if (Line != "")
				{
					clsWork Work = _ConvertLineToWorkObject(Line);
					vWorks.push_back(Work);
				}
			}
			MyFile.close();
		}

		return vWorks;
	}

	static void _SaveWorksDataToFile(vector<clsWork> vWorks)
	{
		fstream MyFile;
		MyFile.open("ToDoList.txt", ios::out); // overwrite
		
		string DataLine;

		if (MyFile.is_open())
		{
			for (clsWork W : vWorks)
			{
				if (W._MarkedForDelete == false)
				{
					// We only write records that are not marked for delete
					DataLine = _ConvertWorkObjectToLine(W);
					MyFile << DataLine << endl;
				}
			}
		}

		MyFile.close();
	}

	void _Update()
	{
		vector <clsWork> _vWork;
		_vWork = _LoadWorksDataFromFile();

		for (clsWork& W : _vWork)
		{
			if (W.WorkNumber == WorkNumber)
			{
				W = *this;
				break;
			}
		}

		_SaveWorksDataToFile(_vWork);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertWorkObjectToLine(*this));
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("ToDoList.txt", ios::out | ios::app); // write and save

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

public:

	clsWork(enMode Mode,string WorkNumber, string WorkName, string WorkDescription, bool WorkDone)
	{
		_Mode = Mode;
		_WorkNumber = WorkNumber;
		_WorkName = WorkName;
		_WorkDescription = WorkDescription;
		_CreationDateTime = clsDate::GetSystemDateTimeString();
		_WorkStatus = WorkDone;
	}

	clsWork(enMode Mode, string WorkNumber, string WorkName, string WorkDescription,
		string CreationDateTime,bool WorkDone)
	{
		_Mode = Mode;
		_WorkNumber = WorkNumber;
		_WorkName = WorkName;
		_WorkDescription = WorkDescription;
		_CreationDateTime = CreationDateTime;
		_WorkStatus = WorkDone;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	void SetWorkNumber(string WorkNumber)
	{
		_WorkNumber = WorkNumber;
	}

	string GetWorkNumber()
	{
		return _WorkNumber;
	}

	__declspec(property (get = GetWorkNumber, put = SetWorkNumber)) string WorkNumber;

	void SetWorkName(string WorkName)
	{
		_WorkName = WorkName;
	}

	string GetWorkName()
	{
		return _WorkName;
	}

	__declspec(property (get = GetWorkName, put = SetWorkName)) string WorkName;

	void SetWorkDescription(string WorkDescription)
	{
		_WorkDescription = WorkDescription;
	}

	string GetWorkDescription()
	{
		return _WorkDescription;
	}

	__declspec(property (get = GetWorkDescription, put = SetWorkDescription)) string WorkDescription;

	void SetWorkStatus(bool WorkStatus)
	{
		_WorkStatus = WorkStatus;
	}

	bool GetWorkStatus()
	{
		return _WorkStatus;
	}

	__declspec(property (get = GetWorkStatus, put = SetWorkStatus)) bool WorkStatus;

	string GetCreationDateTime()
	{
		return _CreationDateTime;
	}

	//void Print()
//{
//	cout << "\nInfo:";
//	cout << "\n_________________________________";
//	cout << "Work Number:      " << _WorkNumber;
//	cout << "Work Name:		   " << _WorkName;
//	cout << "Work Description: " << _WorkDescription;
//	cout << "Work Done:		   " << _WorkDone;
//	cout << "\n_________________________________";
//}

	static vector <clsWork> GetWorksList()
	{
		return _LoadWorksDataFromFile();
	}

	static clsWork Find(string stWorkNumber)
	{
		fstream MyFile;
		MyFile.open("ToDoList.txt", ios::in); // read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsWork Work = _ConvertLineToWorkObject(Line);
				if (Work.WorkNumber == stWorkNumber)
				{
					MyFile.close();
					return Work;
				}
			}
			MyFile.close();
		}
		return _GetEmptyWorkObject();
	}

	static clsWork Find(string stWorkNumber, string stWorkName)
	{
		fstream MyFile;
		MyFile.open("ToDoList.txt", ios::in); // read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsWork Work = _ConvertLineToWorkObject(Line);
				if (Work.WorkNumber == stWorkNumber && Work.WorkName == stWorkName)
				{
					MyFile.close();
					return Work;
				}
			}
			MyFile.close();
		}
		return _GetEmptyWorkObject();
	}

	static bool IsWorkExist(string WorkNumber)
	{
		clsWork Work1 = clsWork::Find(WorkNumber);
		return (!Work1.IsEmpty());
	}

	static clsWork GetAddNewWorkObject(string WorkNumber)
	{
		return clsWork(enMode::AddNewMode, "", "", "", false);
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildWorkNumberExists = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;
		}

		case enMode::UpdateMode:
		{
			_Update();

			return enSaveResults::svSucceeded;
			break;
		}

		case enMode::AddNewMode:
		{
			if (clsWork::IsWorkExist(_WorkNumber))
			{
				return enSaveResults::svFaildWorkNumberExists;
			}
			else
			{
				_AddNew();
				// we need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

			break;
		}
		}
	}

	bool Delete()
	{
		vector<clsWork> _vWorks;
		_vWorks = _LoadWorksDataFromFile();

		for (clsWork& W : _vWorks)
		{
			if (W.WorkNumber == _WorkNumber)
			{
				W._MarkedForDelete = true;
				break;
			}
		}

		_SaveWorksDataToFile(_vWorks);

		*this = _GetEmptyWorkObject();

		return true;
	}
};

