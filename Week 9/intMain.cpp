  //////////////////// ** Author: Jared Parkinson
 //   Main.cpp     // *** Date: 11/23/2015
//////////////////// **** Desc: Week 9 - intSet.hpp

/*////////////////
/
/		 ///////
/		  //  //
/		 /////
/	//  //
/	/////
/
///////////////*/

#include "intSet.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
	intSet setA;
	//intSet setB;
	cout << "Empty? False=0 True=1 :" << setA.isEmtpy() << endl;
	setA.add(5);
	cout << "Contains 5? False=0 True=1 :" << setA.contains(5) << endl;	
	cout << "Empty? False=0 True=1 :" << setA.isEmtpy() << endl;

	//intSet test1;
	//cout << "Size? " << test1.size() << endl;
	//cout << "Empty? False=0 True=1 :" << test1.isEmtpy() << endl;
	
	//test1.add(5);
	//cout << "Empty? False=0 True=1 :" << test1.isEmtpy() << endl;
	//cout << "Size? " << test1.size() << endl;
	//cout << "Contains? False=0 True=1 :" << test1.contains(5) << endl;	

	//int contains(int);
	//void add(int);
	//void remove();
	//void addAll(intSet);
	//void removeDifferent(intSet);
	//void removeSame(intSet);

	system("PAUSE");
	return 0;
}