/*********************************************************************
** Author: Jared Parkinson
** Date: 10/01/2015
** Description: Assignment 2 - Week 2 - Project 2.a - average.cpp
*********************************************************************/

#include <iostream> 
#include <string>

using namespace std;

int main()
{
	//Define Variables
	double num1;
	double num2;
	double num3;
	double num4;
	double num5;	

	//Request User Input of 5 numbers - Hit return to next line
	cout << "Please enter five numbers." << endl;
	cin >> num1;
	cin >> num2;
	cin >> num3;
	cin >> num4;
	cin >> num5;

	//Calculate Sum and Divide by Number Total
	double total = num1 + num2 + num3 + num4 + num5;
	double average = total / 5;

	//Output the Average to the User Screen
	cout << "The average of those numbers is: " << endl;
	cout << average << endl;

	return 0;
}


/*Exact Instructions: 
Please enter five numbers.
- 2.4
5.1
6.0
123.8
- 19.0
The average of those numbers is :
22.7 */