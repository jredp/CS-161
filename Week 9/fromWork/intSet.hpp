  //////////////////// ** Author: Jared Parkinson
 //   intSet.hpp   // ** Date: 11/23/2015
//////////////////// ** Desc: Week 9 - intSet.hpp

//Def Guard
#ifndef INTSET_HPP
#define INTSET_HPP

#include <iostream>
#include <algorithm>
using namespace std;

class intSet
{
	//Data Members
private:	
	int *ptrToInt;
	int currentSize; //Updates when add() method creates bigger array
	int totalIntValues; //Hold current number of values in the array	
public:
	//Function Prototypes
	intSet();
	~intSet();
	int size();
	bool isEmtpy();
	int contains(int) const; //contains() method is a "const function" (so can be called on const params
	void add(int);
	void remove(int);
	void addAll(const intSet&);
	void removeDifferent(const intSet&);
	void removeSame(const intSet&);
};
//End Guard
#endif