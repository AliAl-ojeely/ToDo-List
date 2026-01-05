# 📝 C++ To-Do List System with Active Record

> **A professional, console-based Task Management System built using C++ and Object-Oriented Programming (OOP). This project demonstrates advanced software architecture patterns, file handling, and dynamic UI rendering.**

---

## 🚀 Project Overview

The **To-Do List System** is designed to help users manage daily tasks efficiently. Unlike simple procedural programs, this project implements the **Active Record Pattern**, making the code modular, scalable, and easy to maintain. It supports full persistent storage using text files and features a robust "Work Register" log system.

---

## 🏗️ Architecture & Design Pattern

### 🧠 The Active Record Pattern
This project strictly follows the **Active Record** architectural pattern. instead of having separate manager classes for data access, the `clsWork` object is responsible for its own data persistence.

**How it works in this project:**
The object encapsulates both **Data** and **Behavior**.

```cpp
// Example of Active Record usage in this project:

// 1. Find a record (The object loads itself)
clsWork Work = clsWork::Find("W001");

// 2. Modify data (In-memory update)
Work.WorkName = "Update System Security";
Work.WorkDone = true;

// 3. Save (The object knows how to save itself to the file)
Work.Save(); 

// 4. Delete (The object knows how to remove itself)
Work.Delete();
```

Project Structure
The project is organized into modular Header (.h) and Source (.cpp) files to ensure separation of concerns.

ToDo-List (C++)/
│
├── 📂 Header Files (Logic & Models)
│   ├── clsWork.h                <-- Core Model (Active Record)
│   ├── clsUser.h                <-- User Management
│   ├── clsDate.h                <-- Date & Time Utilities
│   ├── clsString.h              <-- String Manipulation Lib
│   ├── clsInputValidate.h       <-- Input Validation Lib
│   ├── clsScreen.h              <-- Base UI Class
│   └── clsUtil.h                <-- General Utilities
│
├── 🖥️ Header Files (Screens / UI Layer)
│   ├── clsMainScreen.h          <-- Main Menu Entry
│   ├── clsWorkListScreen.h      <-- Display Tasks Table
│   ├── clsAddNewWork.h          <-- Add Task Screen
│   ├── clsUpdateMainScreen.h    <-- Update Menu
│   ├── clsDeleteWorkScreen.h    <-- Delete Interface
│   ├── clsFindWorkScreen.h      <-- Search Interface
│   └── clsWorkRegisterScreen.h  <-- Activity Log View
│
├── 📂 Source Files
│   └── ToDo-List (C++).cpp      <-- Application Entry Point (main)
│
└── 📄 Data Files (Database)
    ├── To-DoList.txt            <-- Main Data Storage
    └── WorkRegister.txt         <-- Transaction Log

Key Features
1. Complete CRUD Operations
Create: Auto-generated Work IDs (e.g., W001, W002).

Read: View all tasks formatted in a dynamic table.

Update: Edit task details or toggle status (Done/Pending).

Delete: Soft or Hard delete capabilities.

2. Intelligent UI & Formatting
Dynamic Word Wrapping: Long descriptions are automatically wrapped to the next line without breaking the table layout.

Status Parsing: Converts boolean values (1/0) into human-readable text (Yes/No or Done/Pending).

3. Work Register (Logging System)
Every time a new task is added, the system automatically logs the transaction in a separate file for auditing.

Log File Format (WorkRegister.txt):

2/1/2026 - 9:30:0#//#W001#//#Network Setup#//#1
2/1/2026 - 11:0:0#//#W002#//#Database Backup#//#1
4/1/2026 - 3:14:0#//#W011#//#Formating Windows 10#//#0

🛠️ Technologies & Tools
Language: C++ (Standard 11/14)

IDE: Microsoft Visual Studio

Concepts: OOP (Encapsulation, Inheritance), File I/O (fstream), Pointers, Vectors.

👤 Author
Ali Nasser Al-Ojeely

Front-End Web Developer & C++ Programmer

📍 Location: Mukalla, Yemen

This project was developed to demonstrate mastery of C++ fundamentals and advanced Architectural Patterns.
