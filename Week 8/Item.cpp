/************************************************
** Author: Jared Parkinson
** Date: 11/18/2015
** Description: Assignment 8 - Week 8 - Item.cpp
************************************************/
#include "Item.hpp"

/**********************************************************************
* Description: Default Constr sets Name NULL, Price and Quan to 0
* Desc: Constructor builds item obj w/supplied params using set Functions
* Parameters: Accepts name(string), price(double), quantity(int)
****************************************************************************/
//Default Constructor
Item::Item()
{
	setName("");
	setPrice(0.0);
	setQuantity(0);
};
//Constructor
Item::Item(string nam, double pri, int qua)
{
	setName(nam);
	setPrice(pri);
	setQuantity(qua);
};
/*************************************************************************
* Description: Set Func - Set private Data Members (name, price, quantity)
* Description: Get Func - Return private Data Members (above)
* Parameters: Only Set Accepts - name(string), price(double), quantity(int)
* Return Value: Set - Private Data Members (name, price, quantity)
*************************************************************************/
//Setters
void Item::setName(string setNam){
	name = setNam;
};
void Item::setPrice(double setPri){
	price = setPri;
};
void Item::setQuantity(int setQua){
	quantity = setQua;
};
//Getters
string Item::getName(){
	return name;
};
double Item::getPrice(){
	return price;
};
int Item::getQuantity(){
	return quantity;
};