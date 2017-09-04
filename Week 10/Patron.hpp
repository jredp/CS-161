
#ifndef PATRON_HPP
#define PATRON_HPP

//#include <string>
#include <vector>
#include "Book.hpp"

//class LibraryItem;

class Patron
{
private:
	std::string idNum;
	std::string name;
	std::vector<Book*> checkedOutBooks; //Vector of Pointers to Book objects
	double fineAmount;
public:
	Patron(std::string idn, std::string n);
	std::string getIdNum();
	std::string getName();
	std::vector<Book*> getCheckedOutBooks();
	void addBook(Book* b);
	void removeBook(Book* b); //remove the Book Object from the Vector using the Pointer 
	double getFineAmount();
	void amendFine(double amount);
};

#endif