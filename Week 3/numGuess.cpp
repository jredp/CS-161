/*********************************************************************
** Author: Jared Parkinson
** Date: 10/11/2015
** Description: Assignment 3 - Week 3 - Project 3.c - numGuess.cpp
*********************************************************************/
#include <iostream> 
using namespace std;

int main()
{
	// Define variables to be used
	int guessedNum, enteredNum, tryCount = 0;
	
	// Request user input the enteredNum / User enters enteredNum
	cout << "Enter the number for the player to guess." << endl;
	cin >> enteredNum;

	// Request user to enter a guess
	cout << "Enter your guess." << endl;	
	do
	{
		cin >> guessedNum; // Enter guessedNum
		tryCount++; // Tick counter up 1 try
			if (guessedNum > enteredNum)
			{
				cout << "Too high - try again." << endl;
			}
			else if (guessedNum < enteredNum)
			{
				cout << "Too low - try again." << endl;
			}			
			else
			{
				cout << "You guessed it in " << tryCount << " tries." << endl;
			}		
	} while (guessedNum != enteredNum);
	
	return 0;
}