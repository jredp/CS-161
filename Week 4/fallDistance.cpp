/*********************************************************************
** Author: Jared Parkinson
** Date: 10/20/2015
** Description: Assignment 4 - Week 4 - Project 4.a - fallDistance.cpp
*********************************************************************/
#include <iostream>
#include <cmath> //To use pow
using namespace std;

//Define Function to be used
double fallDistance(int); 

/* //Main TEST for Return
int main() 
{
	//Define Variables
	int time;

	//Request Time Input
	cout << "input time in seconds\n";
	cin >> time;
	fallDistance(time); //Apply fallDistance function
	cout << fallDistance(time) << endl;
		
	return 0;
} */

/**************************************************************
* Description: Return the [Fall Distance] for [Time in Seconds]
* Parameters: Requires [time] variable in seconds
* Return Value: [Fall Distance] as a double result
**************************************************************/
double fallDistance(int time)
{
	// Return the distance as result when called
	return (.5 * 9.8) * pow(time,2.0);
}