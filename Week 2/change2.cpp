/*********************************************************************
** Author: Jared Parkinson
** Date: 10/1/2015
** Description: Assignment 2 - Week 2 - Project 2.c - change.cpp
*********************************************************************/

#include <iostream> 
#include <string>

using namespace std;

int main()
{
	//Define Variables used - int is for non decimal
	int cents, quartTotal, dimeTotal, nickelTotal, pennyTotal;

	//Print input request to User - User inputs cents
	cout << "Please enter an amount in cents less than a dollar." << endl;
	cin >> cents;

	//Calculation of coin totals using division and Modulation
	quartTotal = cents / 25; //Result is whole number
	cents = cents % 25;
	dimeTotal = cents / 10;
	cents = cents % 10;
	nickelTotal = cents / 5;
	cents = cents % 5;
	pennyTotal = cents / 1;
	cents = cents % 1;

	//Output Total of each coin to user screen
	cout << "Q : " << quartTotal << endl;
	cout << "D : " << dimeTotal << endl;
	cout << "N : " << nickelTotal << endl;
	cout << "P : " << pennyTotal << endl;

	return 0;
}
/*
Exact instructions for assignment 2.c:
Project 2.c
Write a program that asks the user for a(integer) number of cents,
from 0 to 99, and outputs how many of each type of coin would 
represent that amount with the fewest total number of coins.
When you run your program, it should match the following format:

Please enter an amount in cents less than a dollar.
87
Your change will be :
Q : 3
D : 1
N : 0
P : 2
*/

