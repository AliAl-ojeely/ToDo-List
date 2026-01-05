C++ To-Do List System
A robust, console-based Task Management System built using C++ and Object-Oriented Programming (OOP) principles. This project demonstrates advanced file handling, data formatting, and architectural patterns like Active Record.

Overview
The To-Do List System allows users to manage their daily tasks efficiently. It supports full CRUD (Create, Read, Update, Delete) operations, storing data persistently in text files. The system features a clean console user interface with dynamic table formatting and transaction logging.

Architecture & Design Patterns
The Active Record Pattern
This project is built around the Active Record Design Pattern.

Core Class: clsWork

Concept: The clsWork object is responsible for its own data persistence. It encapsulates both the data (Properties like WorkName, WorkStatus) and the behavior (Methods like Save(), Delete(), Find()).

Benefits:

High Cohesion: Logic and data are kept together.

Clean Code: The UI layer (Screens) simply calls methods like NewWork.Save(), without worrying about file handling details.

Self-Managing Objects: The object knows how to add itself to the database or update its own status.

Key Features
CRUD Operations:

Add New Work: Create tasks with auto-generated IDs.

List Works: View all tasks in a formatted table with text-wrapping for long descriptions.

Update Work: Modify task details or toggle status (Done/Pending).

Delete Work: Remove tasks permanently from the file.

Search Functionality: Find specific tasks by ID.

Activity Logging (Work Register): Automatically logs every new task addition into a separate WorkRegister.txt file with a timestamp.

Input Validation: Robust validation using clsInputValidate to ensure data integrity (e.g., valid dates, non-empty strings).

Smart UI:

Dynamic column alignment.

Word-wrapping for long task names and descriptions to fit the console view.

Project Structure
Based on the solution explorer, the project is organized into modular headers and source files:

Core & Model
clsWork.h : The heart of the system (Active Record Model). Handles data and file operations (To-DoList.txt & WorkRegister.txt).

Screens (UI Layer)
clsMainScreen.h : The main menu entry point.

clsWorkListScreen.h : Displays the formatted table of tasks.

clsAddNewWork.h : Interface for creating new tasks.

clsUpdateMainScreen.h : Sub-menu for update operations.

clsUpdateWorkInfoScreen.h : Update task details.

clsUpdateWorkStatusScreen.h : Update task completion status.

clsDeleteWorkScreen.h : Interface for deleting tasks.

clsFindWorkScreen.h : Interface for searching tasks.

clsWorkRegisterScreen.h : Displays the log of added tasks.

Utilities & Libraries
clsScreen.h : Base class for all screens (headers, standardized UI).

clsDate.h : Handles date/time operations and formatting.

clsString.h : String manipulation (splitting, trimming, etc.).

clsInputValidate.h : Validates user inputs (numbers, ranges, strings).

clsUtil.h : General utility functions.

Data Storage
The system uses flat text files as a database:

To-DoList.txt: Stores the main tasks.

Format: WorkID#//#Name#//#Description#//#Date#//#Status

WorkRegister.txt: Stores the history log of added tasks.

Format: Date#//#WorkID#//#Name#//#Status

Technologies Used
Language: C++ (Standard 11/14/17 recommended)

IDE: Microsoft Visual Studio

Paradigm: OOP (Inheritance, Encapsulation, Polymorphism)

Author
Ali Nasser Al-Ojeely

Front-End Web Developer & C++ Programmer

Location: Mukalla, Yemen
