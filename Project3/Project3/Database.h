/*
Samantha Durr
June 13, 2023
*/

#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "ErrorCodes.h"

using namespace std;

/// <Summary>
/// This class encapsulates the functionality of a simple database for the Corner Grocer application. It
/// uses a hash map, which allows items to be quickly looked at.
/// Standard database
/// functions are provided, which includes the ability to backup, find, and update the data in the
/// database.
/// </Summary>
class Database
{
public:
	/// <Summary>
	/// This method creates the database, which causes it to open and read the data file containing the
	/// list of purchased items.
	/// </Summary>
	Database();

	/// <Summary>
	/// This method backs up the accumulated data into a local file named frequency.dat. The backup file contains the
	/// name of the item and the number of times that item appears in the input file used to initialize
	/// the database. The backup file is saved out in CSV, comma delimited format, so that it can be read by
	/// by a word processing program for ease of validation.
	/// </Summary>
	void Backup();

	/// <Summary>
	/// Returns the number of times an item was purchased.
	/// </Summary>
	/// <param name="">The item name to find.</param>
	/// <returns>
	/// The number of times the item has been purchased. If the item is not in the database, which means it has
	/// not been purchased, 0 is returned.
	/// </returns>
	int GetItemCount(string itemName);

	/// <Summary>
	/// Selects all items from the database items table and displays them as an ordered numeric list.
	/// </Summary>
	void SelectAllNumeric();

	/// <Summary>
	/// Selects all items from the database items table and displays them as an ordered histogram list.
	/// </Summary>
	void SelectAllHistogram();
private:
	map<string, int> itemTable;
};

