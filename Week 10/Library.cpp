  //////////////////// ** Author: Jared Parkinson 
 //   Library.cpp  // *** Date: 12/2/2015
//////////////////// **** Desc: Week 10 - Library.cpp  

#include "Library.hpp"

/*---------------------------------------------------------------------------------*/
// Desc: Default Constructor. Sets the currentDate to 0
/*---------------------------------------------------------------------------------*/
Library::Library()
{
	currentDate = 0;
};
/*---------------------------------------------------------------------------------*/
// Desc: Adds a book to the Library (holdings vector) - Increases Vector Size
// Param: Requires & for Book*
/*---------------------------------------------------------------------------------*/
void Library::addBook(Book* addBook)
{
	holdings.push_back(addBook); 
};
/*---------------------------------------------------------------------------------*/
// Desc: Adds a Patron to the Library (members vector) - Increases Vector Size
// Param: Requires & for Patron*
/*---------------------------------------------------------------------------------*/
void Library::addPatron(Patron* addPatron)
{
	members.push_back(addPatron);
};
/*---------------------------------------------------------------------------------*/
// Desc: Checks a Book out from the Library if possible; 
//		 Updates checkedOutBy, dateCheckedOut, Location;
//       Failure Returns Error String;
// Param: Requires Patron idNum, Book idCode
/*---------------------------------------------------------------------------------*/
std::string Library::checkOutBook(std::string pID, std::string bID)
{	
	Book* paramBook = getBook(bID);//set Book for later use
	Patron* paramPat = getPatron(pID); //set Patron for later use	
	/*---------------FAIL--/--SUCCESS-------------------*/
	//FAIL!	
	if (paramBook==NULL)//No Book Error
		return "book not found";	
	else if (paramPat==NULL)//No Patron Error
		return "patron not found";
	else if (paramBook != NULL && paramBook->getCheckedOutBy() != NULL)//Already CheckedOut Error
		return "book already checked out";	
	else if (paramBook->getLocation() == ON_HOLD_SHELF)//onHold Error
		return "book on hold by other patron";		
	//SUCCESS!
	else 
	{		
		paramBook->setCheckedOutBy(paramPat);//Update checkedOutBy
		paramBook->setDateCheckedOut(currentDate);//Update dateCheckedOut
		paramBook->setLocation(CHECKED_OUT);//Update Location				
		if ((paramBook->getRequestedBy()) == paramPat)//Was already onHold / this Patron
			paramBook->setRequestedBy(NULL);
		paramPat->addBook(paramBook); //Update Patron checkedOutBooks
		return "check out successful";		
	}
};
/*---------------------------------------------------------------------------------*/
// Desc: Returns Book to the Library. Places SHELF location. Update Patron/Book members
// Param: Requires Book idCode
/*---------------------------------------------------------------------------------*/
std::string Library::returnBook(std::string bID)
{	
	Book* returnBook = getBook(bID);	
	if (returnBook == NULL) //No book in library
		return "book not found";		
	else if (returnBook->getCheckedOutBy() == NULL) //Not checked out / In library
		return "book already in library";		
	else
	{			
		returnBook->getCheckedOutBy()->removeBook(returnBook);//Remove from checkedOutBooks vec		
		if ((returnBook->getRequestedBy()) == NULL)//No requestedBy
		{			
			returnBook->setLocation(ON_SHELF);//update loc not requested;
			returnBook->setCheckedOutBy(NULL);//checkedOutBy to NULL - in Library
		}
		else
		{			
			//Does not automatically go to requestedBy Patron!;
			returnBook->setLocation(ON_HOLD_SHELF); //Update loc - requested;
			returnBook->setCheckedOutBy(NULL); //Update chkOutBy to NULL
		}		
		return "return successful";
	};
};
/*---------------------------------------------------------------------------------*/
// Desc: requestBook - Request Book be put on Hold Shelf for Patron.
// Params: Patron idNum, Book idCode
/*---------------------------------------------------------------------------------*/
std::string Library::requestBook(std::string pID, std::string bID)
{		
	if (getBook(bID) == NULL) //No Book
		return "book not found";	
	else if (getPatron(pID) == NULL) //No Patron
		return "patron not found";	
	else if ((getBook(bID)->getRequestedBy()) != NULL)//Already Requested
		return "book already on hold";
	else
	{	
		getBook(bID)->setRequestedBy(getPatron(pID));//Update requestedBy		
		if (getBook(bID)->getLocation() == ON_SHELF)//If On Shelf
			getBook(bID)->setLocation(ON_HOLD_SHELF);//Update Shelf Location
		return "request successful";
	}	
};
/*---------------------------------------------------------------------------------*/
// Desc: payFine - Pays down the Patron Fine
// Param: Patron idNum, amount being paid - Positive for paying down
/*---------------------------------------------------------------------------------*/
std::string Library::payFine(std::string pID, double payment)
{	
	if (getPatron(pID) == NULL) //If No Patron
		return "patron not found";	
	
	//Subtract Patron payment from fine
	getPatron(pID)->amendFine(-payment);
	return "payment successful";
};
/*---------------------------------------------------------------------------------*/
// Desc: Increment the current Date. If book overdue, amend Fine of Patron
// Param: Patron idNum, amount being paid - Positive for paying down
/*---------------------------------------------------------------------------------*/
void Library::incrementCurrentDate()
{
	currentDate++;//increment current date	
	for (int i = 0; i<members.size(); ++i)//Each Library Patron Loop
	{
		//The current patron this loop
		Patron* currentPatron = getPatron(members[i]->getIdNum());
		//Loop checked out books by Patron
		for (int p = 0; p<(currentPatron->getCheckedOutBooks().size()); ++p)
		{
			//The current book this loop			
			Book* currentBook = getBook(holdings[p]->getIdCode());
			if (currentDate-(currentBook->getDateCheckedOut())>21) //If Book Overdue
				currentPatron->amendFine(.10); //amendFine of Patron by 10cents
		};		
	}	
};
/*---------------------------------------------------------------------------------*/
// Desc: getPatron - Returns a pointer to the Patron corresponding to the idNum
//	     Return NULL if no such Patron is a member
// Param: Patron idNum
/*---------------------------------------------------------------------------------*/
Patron* Library::getPatron(std::string pID)
{
	//Check for Patron in Patron Class Objects
	Patron* patronPointer = NULL; //Initial NULL
	for (int i=0; i<members.size(); ++i) //Loop per Vec Element
	{
		if (members[i]->getIdNum() == pID)
		{
			patronPointer = members[i];
			return patronPointer;
		}
	};
	return patronPointer;
};
/*---------------------------------------------------------------------------------*/
// Desc: getBook - Returns a pointer to the Book corresponding to the idCode
//	     Return NULL if no such Book is in the holdings
// Param: Book idCode
/*---------------------------------------------------------------------------------*/
Book* Library::getBook(std::string bID)
{		
	//Check for Book in Book Class Objects
	Book* bookPointer = NULL; //Initial NULL
	for (int i=0; i<holdings.size(); ++i) //Loop per Vec Element
		if (holdings[i]->getIdCode() == bID)
		{
			bookPointer = holdings[i];
			return bookPointer;
		}		
	return bookPointer;
};