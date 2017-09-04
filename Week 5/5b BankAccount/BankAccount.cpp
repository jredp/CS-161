/*********************************************************************
** Author: Jared Parkinson
** Date: 10/26/2015
** Description: Assignment 5 - Week 5 - Project 5.a - Box.hpp
*********************************************************************/
#include "BankAccount.hpp" //Include Header
#include <string>
using namespace std;

//Function Definition (implementation) section
/***********************************************************************
* Description: Get Functions. Return the customerName, customerID, customerBalance
* Parameters: Accepts none, uses private data members from Class
* Return Value: volume and surface area of Box Object
************************************************************************/
string BankAccount::getCustomerName()
{
	return customerName;
}
string BankAccount::getCustomerID()
{
	return customerID;
}
double BankAccount::getCustomerBalance()
{
	return customerBalance;
}
/***********************************************************************
* Description: Deposit/Withdraw. Add or subtract from customerBalance
* Parameters: Accepts one double. Manipulates Balance
* Return Value: Returns the customerBalance after manipulation
************************************************************************/
double BankAccount::withdraw(double withd)
{
	customerBalance -= withd;
	return customerBalance;
}
double BankAccount::deposit(double depos)
{
	customerBalance += depos;
	return customerBalance;
}