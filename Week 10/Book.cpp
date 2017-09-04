  //////////////////// ** Author: Jared Parkinson 
 //   Book.cpp     // *** Date: 12/2/2015
//////////////////// **** Desc: Week 10 - Book.cpp  

#include "Book.hpp"

static const int CHECK_OUT_LENGTH = 21; //21 days checkout length
/*---------------------------------------------------------------------------------*/
// Desc: Constructor - Sets idCode, title, author. 
//		 Sets checkedOutBy/requestedBy to NULL / Location to ON_SHELF
// Params: Requires idCode, title, author strings
/*---------------------------------------------------------------------------------*/
Book::Book(std::string idc, std::string t, std::string a)
{
	idCode = idc;
	title = t;
	author = a;	
	setCheckedOutBy(NULL);
	setRequestedBy(NULL);	
	setLocation(ON_SHELF);
};
/*---------------------------------------------------------------------------------*/
// Desc: Getter fucntions. Return: CHECK_OUT_LENGTH, idCode, name, checkedOutBooks,
//		 dateCheckedOut, checkedOutBy, requestedBy Data Members
// Params: None required
/*---------------------------------------------------------------------------------*/
int Book::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
};
std::string Book::getIdCode()
{	
	return idCode;
};
std::string Book::getTitle()
{
	return title;
};
std::string Book::getAuthor()
{
	return author;
};
Locale Book::getLocation()
{
	return location;
};
int Book::getDateCheckedOut()
{
	return dateCheckedOut;
};
Patron* Book::getRequestedBy()
{
	return requestedBy;
};
Patron* Book::getCheckedOutBy()
{
	return checkedOutBy;
};
/*---------------------------------------------------------------------------------*/
// Desc: Setter fucntions. Set location, checkedOutBy, requestedBy, dateCheckedOut
// Params: Locale, Patron*, int
/*---------------------------------------------------------------------------------*/
void Book::setLocation(Locale loc)
{
	location = loc;
};
void Book::setCheckedOutBy(Patron* patCheckOut)
{		
	checkedOutBy = patCheckOut;
};

void Book::setRequestedBy(Patron* patRequestBy)
{
	requestedBy = patRequestBy;
};

void Book::setDateCheckedOut(int setChkOutDate)
{
	dateCheckedOut = setChkOutDate;
};