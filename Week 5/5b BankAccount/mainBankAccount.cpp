#include <iostream>
#include <string>
#include "BankAccount.hpp"
using namespace std;

int main()
{
	BankAccount obj1("Hi", "a123", -333.33);
	cout << obj1.getCustomerName() << endl;
	cout << obj1.getCustomerID() << endl;
	cout << obj1.getCustomerBalance() << endl;	
	cout << obj1.withdraw(33.33) << endl;
	cout << obj1.deposit(44.44) << endl;	
		
	return 0;
}