/*
Samantha Durr
June 13, 2023

   Database implementation.
   This file contains the code that implements the methods used to
   create a simple database of items purchased. The schema for the
   database consists of:
   Table:
   itemsPurchased:
	   ItemName
	   ItemCount

	Due to the simplicity of the customer's requirements, a simple
	hash map is used. This performs the indexed look up for an
	item behind the scenes.

	If the requirements for this application are changed in the
	future, this hash map may need to be replaced with a more
	advanced database system. This is why the application
	is constructed in this manner.

*/
#include "Database.h"

/// <Summary>
/// This method creates the database which causes it to open, and read, the data file containing the
/// list of purchased items.
/// </Summary>
Database::Database()
{
	// The input file stream class used to read the provided list of items.
	ifstream ifStream;
	
    //Enable exception processing for input stream. By default, this
    //is disabled. Since the database is initialized in the constructor,
    //error processing must occur via try/catch and not a return value.
    //Try/catch is also a preferred industry practice, unless stack
    //unwinding is not desirable.

	ifStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		//Opens the input file and initializes the input stream to read the
		//contents of the file.
		ifStream.open("CS210_Project_Three_Input_File.txt");

		//Reads each item in the file and, if it does not
		//exit, adds it to the map. If the item does exist, the count increases.
		while (!ifStream.eof())
		{
			char line[256];
			ifStream >> line;
			if (itemTable.find(line) != itemTable.end())
			{
				itemTable[line]++;
			}
			else
			{
				itemTable[line] = 1;
			}
		}
		ifStream.close();
	}
	catch (std::ifstream::failure e)
	{
		throw ErrorCodes::OpenFailure;
	}
}

/// <Summary>
/// This method backs up the accumulated data into a local file named frequency.dat. The backup file 
/// contains the name of the item and the number of times that item appears in the input file. 
/// This is used to initialize the database. The backup file is saved to a in a CSV, 
/// comma delimited format, so that it can be read by
/// by a word processing program for ease of validation.
/// </Summary>
void Database::Backup()
{
	// Outputs the file stream class used to write the backup file in CSV format.
	ofstream file;

	// Makes sure exceptions are enabled, since error processing is via try catch.
	file.exceptions(std::ofstream::failbit | std::ofstream::badbit);

	try
	{
		file.open("frequency.dat", ofstream::out | ofstream::trunc);
		map<string, int>::iterator it = itemTable.begin();
		while (it != itemTable.end())
		{
			file << it->first << ", " << it->second << endl;
			++it;
		}
		file.close();
	}
	catch (std::ofstream::failure e)
	{
		throw ErrorCodes::BackupFailed;
	}
}

/// <Summary>
/// Returns the number of times an item was purchased.
/// </Summary>
/// <param name="">The item name to find.</param>
/// <returns>
/// The number of times the item has been purchased. If the item is not in the database, which means it has
/// not been purchased, 0 is returned.
/// </returns>
int Database::GetItemCount(string item)
{
	//If the requested item does not exist return 0.
	map<string, int>::iterator it = itemTable.end();
	if (itemTable.find(item) == it)
	{
		return 0;
	}
	//else return the item count.
	return itemTable[item];
}

/// <Summary>
/// Selects all items from the database's items table and displays them as an ordered numeric list.
/// </Summary>
void Database::SelectAllNumeric()
{
	for (auto item : itemTable)
	{
		cout << item.first << " " << item.second << std::endl;
	}
}

/// <Summary>
/// Returns a formatted string containing all of the items in the database with the number of times
/// they have been purchased shown as a series of asterisks.
/// </Summary>
void Database::SelectAllHistogram()
{
	for (auto item : itemTable)
	{
		cout << item.first << " ";
		for (int ii = 0; ii < item.second; ++ii)
		{
			cout << "*";
		}
		cout << endl;
	}
}