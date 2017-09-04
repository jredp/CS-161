  //////////////////// ** Author: Jared Parkinson 
 //   Patron.cpp   // *** Date: 12/2/2015
//////////////////// **** Desc: Week 10 - Patron.cpp  

#include "Patron.hpp"

/*---------------------------------------------------------------------------------*/
// Desc: Constructor. Sets idNum, name and initializes fineAmount to 0
// Params: idNum, name strings
/*---------------------------------------------------------------------------------*/
Patron::Patron(std::string idn, std::string n)
{
	idNum = idn;
	name = n;
	fineAmount = 0;
};
/*---------------------------------------------------------------------------------*/
// Desc: Getter fucntions. Return idNum, name, and checkedOutBooks Data Members
// Params: None required
/*---------------------------------------------------------------------------------*/
std::string Patron::getIdNum()
{
	return idNum;
};
std::string Patron::getName()
{
	return name;
};
std::vector<Book*> Patron::getCheckedOutBooks()
{	
	return checkedOutBooks;
};
/*---------------------------------------------------------------------------------*/
// Desc: Book Posession. Functions: addBook/removeBook to/from Patron chOutVector
// Params Required: Book* / Book*
/*---------------------------------------------------------------------------------*/
void Patron::addBook(Book* b)
{	
	checkedOutBooks.push_back(b); //add book to Patron ChOut_Vector - in posession
};
void Patron::removeBook(Book* b)
{		
	for (int i=0; i<checkedOutBooks.size(); i++)//Loop through vec looking for book
	{		
		if (checkedOutBooks[i]==b)
			checkedOutBooks.erase(checkedOutBooks.begin() +i);//Remove Book
	}	
};
/*---------------------------------------------------------------------------------*/
// Desc: Financials. Return the fineAmount / adujust the fineAmount using amendFine
// Params Required: fineAmount - none / double amount
/*---------------------------------------------------------------------------------*/
double Patron::getFineAmount()
{
	return fineAmount;
};
void Patron::amendFine(double amount)
{
	fineAmount += amount; //Passing Pos will increase / Neg will Decrease
};