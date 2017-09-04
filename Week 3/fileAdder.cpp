/*********************************************************************
** Author: Jared Parkinson
** Date: 10/11/2015
** Description: Assignment 3 - Week 3 - Project 3.b - fileAdder.cpp
*********************************************************************/
#include <iostream>
#include <fstream> // Needed for filework
#include <string>
using namespace std;

int main()
{
	// Define Variables
	ifstream inputFile;
	ofstream outputFile;
	string fileName;
	int fileNumbers, sum=0;

	// Get the filename from the user
	cout << "Please enter a filename... " << endl;
	cin >> fileName;

	// Open the input file
	inputFile.open(fileName.c_str());

	// If the file successfully opened, process it
	if (inputFile) // If this file exists
	{
		// Read numbers from file
		while (inputFile >> fileNumbers)
			sum += fileNumbers;
		
		// Write sum.txt file
		outputFile.open("sum.txt");
		outputFile << sum << endl;
	}
	else // If file does not exist
	{
		// Error message
		cout << "Could not access file." << endl;
	}	
	
	// Close the files
	inputFile.close();
	outputFile.close();

	return 0;
}