/*********************************************************************
** Author: Jared Parkinson
** Date: 10/26/2015
** Description: Assignment 5 - Week 5 - Project 5.a - Box.hpp
*********************************************************************/
//Include Guard
#ifndef BANKACCOUNT_HPP 
#define BANKACCOUNT_HPP

#include <string>
using namespace std;

//Class Declaration (Interface)
class BankAccount
{
	private: // Data Members
		string customerName, customerID;
		double customerBalance;
	public:
		//Constructor - No Default per assignment notes
		BankAccount(string name, string ID, double balance)
		{
			customerName = name;
			customerID = ID;
			customerBalance = balance;
		}
		// Function Prototypes
		string getCustomerName();
		string getCustomerID();
		double getCustomerBalance();
		double withdraw(double);
		double deposit(double);
};
//End Guard
#endif