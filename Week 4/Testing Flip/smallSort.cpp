/*********************************************************************
** Author: Jared Parkinson
** Date: 10/20/2015
** Description: Assignment 4 - Week 4 - Project 4.b - smallSort.cpp
*********************************************************************/
#include <iostream>
using namespace std;

//Declare swap Function
void largeSwap(int&, int&);
//Declare sort Function with reference
void smallSort(int&, int&, int&);

 //Test Main
int main()
{
int a = 14,	b = -90, c = 2;
smallSort(a, b, c);
cout << a << ", " << b << ", " << c << endl;

return 0;
} 

/**************************************************************
* Description: Function swaps 2 integers
* Parameters: Requires (swap1, swap2) as 2 integers
* Return Value: none, just swaps position
**************************************************************/
void largeSwap(int& swap1, int& swap2)
{
	int tempHold = swap1;
	swap1 = swap2;
	swap2 = tempHold;	
}

/**************************************************************
* Description: Function sorts 3 integers a,b,c to min/max
* Parameters: Requires (a, b, c) as 3 integers
* Return Value: swaps a(min) b(middle) c(max)
**************************************************************/
void smallSort(int& a, int& b, int& c)
{
	//Determine min/max: Swap accordingly
	if (a > b) largeSwap(a, b);
	if (a > c) largeSwap(a, c);
	if (b > c) largeSwap(b, c);
}