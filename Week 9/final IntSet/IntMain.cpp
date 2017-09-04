  //////////////////// ** Author: Jared Parkinson
 //   Main.cpp     // *** Date: 11/23/2015
//////////////////// **** Desc: Week 9 - IntMain.cpp

/*///////////////////
/				  //
/		 ///////  /
/		  //  //  /
/		 /////    /
/	//  //        /
/	/////         /
/                /
///////////////*/

#include "IntSet.hpp"
#include <iostream>
using namespace std;
int main()
{
	/*-----------------------------------------------------*/
	//Test1
	cout << "TEST 1: " << endl;

	IntSet a;
	IntSet b;

	cout << "a.isEmpty before:: " << a.isEmtpy() << endl;
	cout << "b.isEmpty before:: " << b.isEmtpy() << endl;	

	a.add(5);
	a.add(5);
	b.add(5);	
	b.add(6);

	cout << "a.isEmpty after adding:: " << a.isEmtpy() << endl;
	cout << "b.isEmpty after adding:: " << b.isEmtpy() << endl;

	cout << "a.size | should be 1: " << a.size() << endl;
	cout << "b.size | should be 2: " << b.size() << endl;

	/*-----------------------------------------------------*/
	//Test2
	cout << "\nTEST 2 addAll: " << endl;

	IntSet c;
	IntSet d;

	c.add(6);
	c.add(6);
	d.add(2);
	d.add(4);
	d.add(3);

	c.addAll(d);
	cout << "c size should be 4, 6,2,4,3 in there::: " << c.size() << endl;	
	
	d.addAll(c);
	cout << "d size should be 4, 6,2,4,3 in there::: " << d.size() << endl;

	/*-----------------------------------------------------*/
	//Test3
	cout << "\nTEST 3 removeDifferent: " << endl;

	IntSet e;
	IntSet f;

	e.add(6);
	e.add(6);
	f.add(2);
	f.add(4);
	f.add(3);

	cout << "e size before removeDifferent - 1 (6):  " << e.size() << endl;
	e.removeDifferent(f);
	cout << "e size after removal - 0:  " << e.size() << endl;

	/*-----------------------------------------------------*/
	//Test4
	cout << "\nTEST 4 removeSame: " << endl;

	IntSet x;
	IntSet y;

	x.add(1);
	x.add(3);
	y.add(3);
	y.add(1);
	y.add(4);

	cout << "x size before removesame - 2:  " << x.size() << endl;
	x.removeSame(y);
	cout << "x size after removal - 0:  " << x.size() << endl;

	//system("PAUSE");
	return 0;

}