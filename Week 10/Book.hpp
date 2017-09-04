
#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>

class Patron;

// These three locations are mutually exclusive, but note that
// a Book can be on request for a Patron while being checked
// out to another Patron.  In that case the Book's location is
// CHECKED_OUT, and when it is returned, it's location will
// become ON_HOLD_SHELF.
enum Locale { ON_SHELF, ON_HOLD_SHELF, CHECKED_OUT };


class Book
{
private:
	std::string idCode; //unique identifier for a Book, think library bar code
	std::string title; //title - cannot be assumed to be unique	
	std::string author; //provided in constructor
	//location - a Book can be either on the shelf, on the hold shelf, or checked out
	Locale location;
	//checkedOutBy - pointer to Patron who has it checked out(if any)
	Patron* checkedOutBy;
	//requestedBy - pointer to Patron who has requested it(if any)
	//a Book can only be requested by one Patron at a time
	Patron* requestedBy;
	//dateCheckedOut - when a book is checked out, this will be set to the currentDate of the Library
	int dateCheckedOut;
public:
	static const int CHECK_OUT_LENGTH = 21; //21 days checkout length
	//constructor - takes an idCode, title and author; 
	//checkedOutBy and requestedBy should be initialized to NULL; 
	//a new Book should be on the shelf
	Book(std::string idc, std::string t, std::string a);
	int getCheckOutLength();
	std::string getIdCode();
	std::string getTitle();
	std::string getAuthor();
	Locale getLocation();
	void setLocation(Locale);
	Patron* getCheckedOutBy();
	void setCheckedOutBy(Patron*);
	Patron* getRequestedBy();
	void setRequestedBy(Patron*);
	int getDateCheckedOut();
	void setDateCheckedOut(int);
};

#endif