/********************************************************
** Author: Jared Parkinson
** Date: 11/18/2015
** Description: Assignment 8 - Week 8 - ShoppingCart.cpp
********************************************************/
#include "ShoppingCart.hpp"

/****************************************************************************
* Desc: Default Constr sets every array Element to NULL / arrayEnd count to 0
* Parameters: None
****************************************************************************/
//Default Constructor
ShoppingCart::ShoppingCart()
{
	for (int i = 0; i<100; ++i)
		itemArray[i] = NULL;
	arrayEnd = 0;
};
/*********************************************************************
* Desc: addItem adds a Item Object to the array by using the arrayEnd
*	counter to determine the position. Increments arrayEnd when done.
* Parameters: Address of Item Object (&itemObjectName)
*********************************************************************/
void ShoppingCart::addItem(Item *cartItem)
{
	itemArray[arrayEnd]=cartItem;
	++arrayEnd;
};
/*********************************************************************
* Desc: totalPrice sums the Item Object Prices in the Array by looping
*	through each item, gets the price, and adds it to the sumOfPrice.
* Parameters: None
*********************************************************************/
double ShoppingCart::totalPrice()
{
	double sumOfPrice = 0;
	for (int i=0; i<arrayEnd; ++i)
	{
		Item *ptr = itemArray[i];
		//Equiv to (*ptr).getQuantity();
		sumOfPrice += (ptr->getPrice()) * (ptr->getQuantity());
	}
	return sumOfPrice;
};