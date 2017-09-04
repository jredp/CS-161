/*********************************************************************
** Author: Jared Parkinson
** Date: 10/20/2015
** Description: Assignment 4 - Week 4 - Project 4.c - hailstone.cpp
*********************************************************************/
#include <iostream>
using namespace std;

//Declare Function
int hailstone(int);

/* //Test Main
int main()
{
//Declare Variable
int startInteger;

cout << "Enter an int" << endl;
cin >> startInteger;
cout << hailstone(startInteger) << endl;

return 0;
} */

/**************************************************************
* Description: Function using even/odd and math to reach 1
* Parameters: Requires [startInteger] for starting point
* Return Value: [count] how many passes through to reach 1
**************************************************************/
int hailstone(int startInteger)
{
	int count = 0; // Set count to 0	
	while (startInteger != 1) // While int isn't 1
	{
		count++; // Count+1 per loop run
		if ((startInteger % 2) == 0) // Is Even		
			startInteger /= 2;
		else if ((startInteger % 2) == 1) // Is Odd
			startInteger *= 3, startInteger++;		
	}
	return count;
}