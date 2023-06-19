/*
 Samantha Durr
 June 13, 2023
 Project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
*/

#include "Database.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <map>
#include <string>
#include "Menu.h"

using namespace std;

// Returned to the operating system to indicate that the Corner Grocer application indicating a successful run.
const int SuccessfullRun = 0;


int main()
{
	try
	{
		// Creates and opens the database, which will read the list of purchased items, index it, and backup the data.
		Database db;

		db.Backup();

		// Creates the class that manages the corner grocer menu.
		Menu menu;


		do
		{
			menu.DisplayMenu();
			menu.ProcessUserInput();
			switch (menu.userSelection)
			{
				case Menu::SelectedMenuOptions::Search:
					{
						string item;
						cout << "Enter the grocery item to search for:";
						cin >> item;
						int count = db.GetItemCount(item);
						cout << "Item " << item << " was found " << count << " times. " << endl;
					}
					break;
				case Menu::SelectedMenuOptions::ListAllNumeric:
					db.SelectAllNumeric();
					break;
				case Menu::SelectedMenuOptions::ListAllHistogram:
					db.SelectAllHistogram();
					break;
				default:
					break;
			}


		} while (menu.userSelection != Menu::SelectedMenuOptions::ExitProgram);

	}
	catch (ErrorCodes errorCode)
	{
		if (errorCode == ErrorCodes::OpenFailure)
		{
			cout << "The data file CS210_Project_Three_Input_File.txt is missing or corrupt, please reload from backup.";

			// Non-zero return informs the operating system that the application did not run successfully. This allows
			// the program to be added to an application system. For example, a batch script can read this value and
			// know the program did not run successfully.
			return (int)ErrorCodes::OpenFailure;
		}
		else if (errorCode == ErrorCodes::BackupFailed)
		{
			cout << "Failed to create the backup file frequency.dat, please check that the application has write access to the folder the application is in.";
			return (int)ErrorCodes::BackupFailed;
		}
	}

	cout << "Press any key to exit.";
	(void)_getch();

	return SuccessfullRun;
}

