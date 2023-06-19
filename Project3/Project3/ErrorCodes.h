/*
 Samantha Durr
 June 13, 2023
 Error codes in use by the corner grocer program.
 */

#pragma once
///<Summary>
/// These are the error return codes for database method returns. These codes are setup so that they can be
/// thrown an caught at the highest level of the application and returned to the operating
/// system. This allows the application to be run from a bash, batch, or other type of job system
/// as a part of an application system.
///</Summary>
enum class ErrorCodes
{
	/// <Summary>
	/// The operation was a success, no error occured.
	/// </Summary>
	Success = 0,

	/// <Summary>
	/// The input file CS210_Project_Three_Input_File.txt failed to open or be processed correctly.
	/// </Summary>
	OpenFailure = 1,
	/// <Summary>
	/// Failed to create or write to the backup file frequency.dat.
	/// </Summary>
	BackupFailed = 2
};

