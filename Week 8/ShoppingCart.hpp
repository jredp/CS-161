/*******************************************************
** Author: Jared Parkinson
** Date: 11/18/2015
** Description: Assignment 8 - Week 8 - ShoppingCart.hpp
********************************************************/
//Def Guard
#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP

#include "Item.hpp"

class ShoppingCart //Class Declaration
{
private: //Private Data Member Declaration
	Item *itemArray[100]; //Array of 100 pointers for Item objects
	int arrayEnd;
public:
	//Default Constructor
	ShoppingCart();
	void addItem(Item *cartItem);
	double totalPrice();
};

//End Guard
#endif