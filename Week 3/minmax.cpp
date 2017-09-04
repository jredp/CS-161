/*********************************************************************
** Author: Jared Parkinson
** Date: 10/11/2015
** Description: Assignment 3 - Week 3 - Project 3.a - minmax.cpp
*********************************************************************/
#include <iostream>
using namespace std;

int main()
{
	// Define Variables
	int singleInt, numOfInts, intMin, intMax;
	
	// Request user input - total number of integers desired
	cout << "How many integers would you like to enter?" << endl;
	cin >> numOfInts;

	// Request user input of total ints they chose - 1 per return
	cout << "Please enter " << numOfInts << " integers." << endl;

	// For loop to count down number of ints entered
	for (int intCount=0; intCount < numOfInts; intCount++)
	{
		cin >> singleInt; // User input single int per loop

		// Eval variables each pass through of 'for loop'
		if (intCount > 0)
		{
			if (singleInt > intMax)
			{
				intMax = singleInt;
			}
			else if (singleInt < intMin)
			{
				intMin = singleInt;
			}
		}
		else
		{
			intMin = singleInt;
			intMax = singleInt;
		}
	}
	
	// Output the min and max ingeters to the user screen
	cout << "min: " << intMin << endl;
	cout << "max: " << intMax << endl;
		
	return 0;
}