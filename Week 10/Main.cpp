#include <string>
#include "Library.hpp"
#include <iostream>

using namespace std;

void TestTimsSet();
void TestTimsSet2();
void TestBook(Book&, Patron&);
void TestBookA(Book, Patron);
Book CreateBookA();
Book CreateBookB();
Patron CreatePatronA();
Patron CreatePatronB();
Library CreateLibraryA();
void TestPatronA(Patron&, Book&);
void TestLibraryA(Library*, Patron*, Book*);

void Print_checkedOutBy(Book&);
void Print_requestedBy(Book&);
int Print_dateCheckedOut(Book&);
void Print_checkedOutBooks(Patron&);

int main()
{
	Book bookA = CreateBookA();
	Patron patronA = CreatePatronA();
	Library lib = CreateLibraryA();
	TestBookA(bookA, patronA);
	TestPatronA(patronA, bookA);
	TestLibraryA(&lib, &patronA, &bookA);
	TestTimsSet2();

	//system("PAUSE");
	return 0;
}

void TestBookA(Book b, Patron p)
{
	cout << "b.getCheckOutLength: 21| " << b.getCheckOutLength() << endl;
	cout << "b.getIdCode: 01| " << b.getIdCode() << endl;
	cout << "b.getTitle: Brothers Karamazov| " << b.getTitle() << endl;
	cout << "b.getAuthor: Dostoevsky| " << b.getAuthor() << endl;
	cout << "b.getLocation: ON_SHELF (0)| " << b.getLocation() << endl;
	b.setLocation(CHECKED_OUT);
	cout << "b.setLocation: CHECKED_OUT (2)| " << b.getLocation() << endl;
	cout << "b.getCheckedOutBy(): NOT | ";
	Print_checkedOutBy(b);
	cout << "b.setCheckedOutBy(): Igor| ";
	b.setCheckedOutBy(&p);
	Print_checkedOutBy(b);
	cout << "b.getRequestedBy(): Nobody| ";
	Print_requestedBy(b);
	b.setRequestedBy(&p);
	cout << "b.setRequestedBy(&p): Igor| ";
	Print_requestedBy(b);
	cout << "b.getDateCheckedOut: garbage, not set|";
	Print_dateCheckedOut(b);
}


void TestBook(Book &b, Patron &p)
{
	cout << "b.getCheckOutLength: " << b.getCheckOutLength() << endl;
	cout << "b.getIdCode: " << b.getIdCode() << endl;
	cout << "b.getTitle: " << b.getTitle() << endl;
	cout << "b.getAuthor: " << b.getAuthor() << endl;
	cout << "b.getLocation: " << b.getLocation() << endl;
	b.setLocation(CHECKED_OUT);
	cout << "b.setLocation:  " << b.getLocation() << endl;
	cout << "b.getCheckedOutBy(): ";
	Print_checkedOutBy(b);
	cout << "b.setCheckedOutBy(): ";
	b.setCheckedOutBy(&p);
	Print_checkedOutBy(b);
	cout << "b.getRequestedBy(): ";
	Print_requestedBy(b);
	b.setRequestedBy(&p);
	cout << "b.setRequestedBy(&p): ";
	Print_requestedBy(b);
	cout << "b.getDateCheckedOut: ";
	Print_dateCheckedOut(b);
}

void TestPatronA(Patron &p, Book &b)
{
	cout << "p.getIdNum(): 001A| " << p.getIdNum() << endl;
	cout << "p.getName(): Igor| " << p.getName() << endl;
	cout << "getCheckedOutBooks(): None| ";
	Print_checkedOutBooks(p);
	cout << "p.addBook(b): 01| ";
	p.addBook(&b);
	Print_checkedOutBooks(p);
	p.removeBook(&b);
	cout << "p.removeBook(b): no books checked out| ";
	Print_checkedOutBooks(p);
	cout << "p.getFineAmount: 0| " << p.getFineAmount() << endl;
	cout << "p.amendFine(1.5): 1.5| ";
	p.amendFine(1.5);
	cout << p.getFineAmount() << endl;
}


void TestLibraryA(Library *L, Patron *p, Book *b)
{
	cout << "L->checkOutBook(001A,01): no book| " << L->checkOutBook("001A", "01") << endl;
	cout << "L->requestBook(001A,01): no book| " << L->requestBook("001A", "01") << endl;
	L->addBook(b);
	cout << "L->addBook(b)" << endl;
	cout << "L->getBook(01).getIdCode: 01| ";
	Book *addedBook = L->getBook("01");
	cout << addedBook->getIdCode() << endl;
	cout << "L->checkOutBook(001A,01): no patron| " << L->checkOutBook("001A", "01") << endl;
	cout << "L->requestBook(001A,01): no patron| " << L->requestBook("001A", "01") << endl;
	L->addPatron(p);
	cout << "L->addPatron(p)" << endl;
	cout << "L->checkOutBook(001A,01): success| " << L->checkOutBook("001A", "01") << endl;
	cout << "L->checkOutBook(001A,01): already checked out| " << L->checkOutBook("001A", "01") << endl;
	Patron patronB = CreatePatronB();
	cout << "L->checkOutBook(002B,01): no patron found| " << L->checkOutBook("002B", "01") << endl;
	L->addPatron(&patronB);
	Book bookB = CreateBookB();
	L->addBook(&bookB);
	cout << "L->addBook(bookB)" << endl;
	cout << "L->getBook(02).getIdCode: 02| ";
	Book *addedBook2 = L->getBook("02");
	cout << addedBook2->getIdCode() << endl;
	cout << "L->checkOutBook(001A,02): success| " << L->checkOutBook("001A", "02") << endl;
	cout << "L->checkOutBook(002B,01): already checked out| " << L->checkOutBook("002B", "01") << endl;
	for (int i = 0; i<7; i++)
		L->incrementCurrentDate();
	cout << "p->getFineAmount() 7 days 1.5| " << p->getFineAmount() << endl;
	for (int i = 0; i<15; i++)
		L->incrementCurrentDate();
	cout << "p->getFineAmount() 22 days 1.7 | " << p->getFineAmount() << endl;
	L->payFine(p->getIdNum(), 1.7);
	cout << "L->payFine(p->getIdNum(),1.7) 0.0 or #e-16| " << p->getFineAmount() << endl;
	cout << "L->returnBook(03): not found | " << L->returnBook("03") << endl;
	cout << "b->getCheckedOutBy->getName(): Igor|" << b->getCheckedOutBy()->getName() << endl;
	b->setRequestedBy(&patronB);
	cout << "b->getRequestedBy->getName: Min|" << b->getRequestedBy()->getName() << endl;
	cout << "b->getLocation(): CHECKED OUT(2)| " << b->getLocation() << endl;
	cout << "L->requestBook(002B,01): already on hold | " << L->requestBook("002B", "01") << endl;
	cout << "L->returnBook(01): successful | " << L->returnBook("01") << endl;
	cout << "L->checkOutBook(001A,01): on hold by another| " << L->checkOutBook("001A", "01") << endl;
	cout << "b->getCheckedOutBy: 0|" << b->getCheckedOutBy() << endl;
	cout << "b->getRequestedBy: address, not 0|" << b->getRequestedBy() << endl;
	Patron *null = NULL;
	b->setRequestedBy(null);
	cout << "b->setRequestedBy(null): 0|" << b->getRequestedBy() << endl;
	cout << "L->returnBook(01): already returned | " << L->returnBook("01") << endl;
}

void Print_checkedOutBooks(Patron &p)
{
	if ((p.getCheckedOutBooks()).size()>0)
	{
		for (int i = 0; i<p.getCheckedOutBooks().size(); i++)
		{
			cout << p.getCheckedOutBooks()[i]->getIdCode();
		}
	}
	else
	{
		cout << "no books checked out";
	}
	cout << endl;
}

void Print_checkedOutBy(Book &b)
{
	if (b.getCheckedOutBy() == NULL)
	{
		cout << "Not checked out";
	}
	else
	{
		cout << b.getCheckedOutBy()->getName();
	}
	cout << endl;
}

void Print_requestedBy(Book &b)
{
	if (b.getRequestedBy() == NULL)
	{
		cout << "Not requested";
	}
	else
	{
		cout << b.getRequestedBy()->getName();
	}
	cout << endl;
}

int Print_dateCheckedOut(Book &b)
{
	cout << b.getDateCheckedOut() << endl;
	return b.getDateCheckedOut();
}


Book CreateBookA()
{
	Book b("01", "Brothers Karamazov", "Dostoevsky");
	cout << "Book: 01, Brothers Karamazov, Doestoevsky" << endl;
	return b;
}

Book CreateBookB()
{
	Book b("02", "Book of Laughter and Forgetting", "Kundera");
	cout << "Book: 02, Book of Laughter and Forgetting, Kundera" << endl;
	return b;
}

Patron CreatePatronA()
{
	Patron igor("001A", "Igor");
	cout << "Patron: 001A Igor" << endl;
	return igor;
}

Patron CreatePatronB()
{
	Patron min("002B", "Min");
	cout << "Patron: 002B Min" << endl;
	return min;
}

Library CreateLibraryA()
{
	Library myLib;
	cout << "Library created" << endl;
	return myLib;
}

void TestTimsSet()
{
	Book b1("123", "War and Peace", "Tolstoy");
	Book b2("234", "Moby Dick", "Melville");
	Book b3("345", "Phantom Tollbooth", "Juster");
	Patron p1("abc", "Felicity");
	Patron p2("bcd", "Waldo");
	Library lib;
	lib.addBook(&b1);
	lib.addBook(&b2);
	lib.addBook(&b3);
	lib.addPatron(&p1);
	lib.addPatron(&p2);
	lib.checkOutBook("bcd", "234");
	for (int i = 0; i<7; i++)
		lib.incrementCurrentDate();
	lib.checkOutBook("bcd", "123");
	lib.checkOutBook("abc", "345");
	for (int i = 0; i<24; i++)
		lib.incrementCurrentDate();
	lib.payFine("bcd", 0.4);
	double p1Fine = p1.getFineAmount();
	double p2Fine = p2.getFineAmount();
}


void TestTimsSet2()
{
	Book b1("123", "War and Peace", "Tolstoy");
	Book b2("234", "Moby Dick", "Melville");
	Book b3("345", "Phantom Tollbooth", "Juster");
	Patron p1("abc", "Felicity");
	Patron p2("bcd", "Waldo");
	Library lib;
	lib.addBook(&b1);
	lib.addBook(&b2);
	lib.addBook(&b3);
	lib.addPatron(&p1);
	lib.addPatron(&p2);
	lib.checkOutBook("bcd", "234");
	lib.requestBook("abc", "234");
	for (int i = 0; i<7; i++)
		lib.incrementCurrentDate();
	lib.checkOutBook("bcd", "123");
	cout << "b2.getDateCheckedOut(): 0| " << b2.getDateCheckedOut() << endl;
	cout << "b1.getDateCheckedOut(): 7| " << b1.getDateCheckedOut() << endl;
	cout << "lib.returnBook(234)" << lib.returnBook("234") << endl;
	cout << "b2.getLocation(): ON_HOLD_SHELF (1)| " << b2.getLocation() << endl;
	lib.checkOutBook("abc", "345");
	for (int i = 0; i<24; i++)
		lib.incrementCurrentDate();
	lib.payFine("bcd", 0.4);
	cout << "p1 fine: 0.3| " << p1.getFineAmount() << endl;
	cout << "p2 fine: -0.1 | " << p2.getFineAmount() << endl;
}

//#include <iostream>
//#include <string>
//#include "Library.hpp"
//
//using namespace std;
//int main()
//{
////create 3 books and 2 patrons
//Book b1("123", "War and Peace", "Tolstoy");
//Book b2("234", "Moby Dick", "Melville");
//Book b3("345", "Phantom Tollbooth", "Juster");
//Patron p1("abc", "Felicity");
//Patron p2("bcd", "Waldo");
//
////BOOKS
//Library lib; //create library
//lib.addBook(&b1);//add address of b1
//lib.addBook(&b2);//add address of b2
//lib.addBook(&b3);//add address of b3
//lib.addPatron(&p1); //add address of patron 1
//lib.addPatron(&p2); //add address of patron 2
//
//cout << b1.getTitle() << endl;
//cout << b1.getIdCode() << endl;
//cout << b1.getAuthor() << endl;
//
//lib.checkOutBook("bcd", "123"); //p2 checkout book 123
//lib.checkOutBook("bcd", "234");//p2 checkout book 234
//for (int i = 0; i<7; i++) //increment date 7 days
//	lib.incrementCurrentDate();
//
//lib.checkOutBook("abc", "345");//p2 checkout book 234
//cout << "Book 1 - 123 is checked out by: " << b1.getCheckedOutBy()->getName() << endl;
//cout << "Book 2 - 234 is checked out by: " << b2.getCheckedOutBy()->getName() << endl;
//
///*/FINES--------------------------------------------------
//double p1Fine = p1.getFineAmount();
//cout << "Before 24 day Fine Patron 1: " << p1Fine << endl;
//double p2Fine = p2.getFineAmount();
//cout << "Before 24 day Fine Patron 2: " << p2Fine << endl;
//
////Accrue
//for (int i = 0; i<24; i++) //increment date 24 days
//	lib.incrementCurrentDate();
//p1Fine = p1.getFineAmount();
//p2Fine = p2.getFineAmount();
//cout << "After Accrual/Before Fine Pay Patron 1: " << p1Fine << endl;
//cout << "After Accrual/Before Fine Pay Patron 2: " << p2Fine << endl;
//
////Pay
//p1Fine = p1.getFineAmount();
//p2Fine = p2.getFineAmount();
//
//lib.payFine("abc", 5.4); 
//lib.payFine("bcd", 0.4);
//
//p1Fine = p1.getFineAmount();
//p2Fine = p2.getFineAmount();
//cout << "After Fine Payment Patron 1: Paid 5.4: " << p1Fine << endl; 
//cout << "After Fine Payment Patron 2: Paid .04: " << p2Fine << endl;*/
//
////Book actions
//lib.requestBook("abc", "123"); //p2 request book that p1 has
//lib.returnBook("123"); //p1 returns book 123
//lib.requestBook("abc", "123"); //p2 request book 123, now returned



//
//system("PAUSE");
//return 0;
//}