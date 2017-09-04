/*********************************************************************
** Author: Jared Parkinson
** Date: 10/1/2015
** Description: Assignment 2 - Week 2 - Project 2.b - tempConvert.cpp
*********************************************************************/

#include <iostream> 
#include <string>

using namespace std;

int main()
{
	//Define Celsius Input Variable
	double celsTemp;
		
	//Request user input a Celcius Temp
	cout << "Please enter a Celsius temperature." << endl;
	cin >> celsTemp;
	
	//Calculate conversion after user input
	double convertTemp = (1.8 * celsTemp) + 32;

	//Output the converted Temp using calculated convertTemp
	cout << "The equivalent Fahrenheit temperature is: " << endl;
	cout << convertTemp << endl;

	return 0;
}

/*
Exact instructions for assignment:
When you run your program, it should match the following format :
Please enter a Celsius temperature.
-10.5
The equivalent Fahrenheit temperature is:
13.1
*/