/*
Samantha Durr
June 13, 2023
*/

#include <string>
#include "Menu.h"
#include <iostream>

using namespace std;

/// <Summary>
/// Displays the menu for the Corner Grocer.
/// <Summary>
void Menu::DisplayMenu()
{
	cout << " Corner Grocer " << endl;
	cout << " 1   Search for a purchased item." << endl;
	cout << " 2   List all purchased items and the number of times they have been purchased." << endl;
	cout << " 3   Display a histogram of all items purchased." << endl;
	cout << " 4   Exit this program." << endl;
}

/// <Summary>
/// Gets the user menu selection and prevents invalid entries from throwing exceptions or processing
/// errors.
/// </Summary>
void Menu::ProcessUserInput()
{
	userSelection = SelectedMenuOptions::None;
	while (userSelection == SelectedMenuOptions::None)
	{
		//Entering the user information into a string, allows the application to
		//validate that the user is only entering a number and that it is in the range
		//of the supported menu options. Entering information from an input stream
		//directly into an integer causes complications. This is due to the stream buffers characters
		//still being stored in the stream buffer. Note: It is compiler specific how
		//cin is implemented, so this approach is preferred.
		string streamText;
		cin >> streamText;
		if (streamText.length() > 1 || streamText[0] < '1' || streamText[0] > '4')
		{
			cout << "Please select a valid menu option by entering its number." << endl;
			continue;
		}
		switch (streamText[0])
		{
		case '1':
			userSelection = SelectedMenuOptions::Search;
			break;
		case '2':
			userSelection = SelectedMenuOptions::ListAllNumeric;
			break;
		case '3':
			userSelection = SelectedMenuOptions::ListAllHistogram;
			break;
		case '4':
			userSelection = SelectedMenuOptions::ExitProgram;
			break;
		}
	}
}