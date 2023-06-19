/*
  Samantha Durr
  June 13, 2023

  This file defines the menu used with the corner grocer application.
 */

#pragma once

/// <Summary>
/// This class handles the display and user interaction with the corner grocer's main menu.
/// </Summary>
class Menu
{
public:
	/// <Summary>
	/// This enum represents the possible menu options to the corner grocer program. 
	/// </Summary>
	enum class SelectedMenuOptions
	{
		/// <Summary>
		/// Used to represent that the user has not selected any option.
		/// </Summary>
		None = 0,

		/// <Summary>
		/// User selected the search for an item option.
		/// </Summary>
		Search = 1,

		/// <Summary>
		/// User selected the list all items and their count option.
		/// </Summary>
		ListAllNumeric = 2,

		/// <Summary>
		/// User selected the list all items in a histogram format.
		/// </Summary>
		ListAllHistogram = 3,

		/// <Summary>
		/// User selected the exit program option.
		/// </Summary>
		ExitProgram = 4
	};

	/// <Summary>
	/// Contains the user's menu selection.
	/// </Summary>
	SelectedMenuOptions userSelection;

	/// <Summary>
	/// Displays the menu for the Corner Grocer.
	/// <Summary>
	void DisplayMenu();

	/// <Summary>
	/// Gets the user menu selection and prevents invalid entries from throwing exceptions or processing
	/// errors.
	/// </Summary>
	void ProcessUserInput();
};