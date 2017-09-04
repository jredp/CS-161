/************************************************
** Author: Jared Parkinson
** Date: 11/18/2015
** Description: Assignment 8 - Week 8 - Item.hpp
************************************************/
//Def Guard
#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
using std::string;

class Item //Class Declaration
{	
private: //Private Data Member Declaration
	string name;
	double price;
	int quantity;
public:	
	Item();	//Default Constructor
	Item(string nam, double pri, int qua); //Constructor
	//Getters
	string getName();
	double getPrice();
	int getQuantity();
	//Setters
	void setName(string);
	void setPrice(double);	
	void setQuantity(int);
};
//End Guard
#endif