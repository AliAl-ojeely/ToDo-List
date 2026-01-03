#pragma once
#include <iostream>
#include <string>

using namespace std;

class clsWork
{
private:
	string _WorkNumber;
	string _WorkName;
	string _WorkDescription;
	string _CreationDateTime;
	bool _WorkDone;

public:

	clsWork(string WorkNumber, string WorkName, string WorkDescription, bool WorkDone)
	{
		_WorkNumber = WorkNumber;
		_WorkName = WorkName;
		_WorkDescription = WorkDescription;
		_CreationDateTime = clsDate::GetSystemDateTimeString();
		_WorkDone = WorkDone;
	}

	clsWork(string WorkNumber, string WorkName, string WorkDescription, 
		string CreationDateTime,bool WorkDone)
	{
		_WorkNumber = WorkNumber;
		_WorkName = WorkName;
		_WorkDescription = WorkDescription;
		_CreationDateTime = CreationDateTime;
		_WorkDone = WorkDone;
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

	void SetWorkDone(bool WorkDone)
	{
		_WorkDone = WorkDone;
	}

	bool GetWorkDone()
	{
		return _WorkDone;
	}

	__declspec(property (get = GetWorkDone, put = SetWorkDone)) bool WorkDone;

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
};

