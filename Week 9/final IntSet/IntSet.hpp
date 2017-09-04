  //////////////////// ** Author: Jared Parkinson
 //   IntSet.hpp   // *** Date: 11/23/2015
//////////////////// **** Desc: Week 9 - IntSet.hpp

//Define Guard
#ifndef IntSet_HPP
#define IntSet_HPP

#include <iostream>
#include <algorithm>
using namespace std;

class IntSet
{
	//Data Members
private:	
	int *ptrToInt;
	int currentSize; //Updates when add() method creates bigger array
	int totalIntValues; //Hold current number of INT values in the array	
public:
	//Function Prototypes
	IntSet();
	~IntSet();
	int size();
	bool isEmtpy();
	int contains(int) const; 
	void add(int);
	void remove(int);
	void addAll(const IntSet&);
	void removeDifferent(const IntSet&);
	void removeSame(const IntSet&);
};
//End Guard
#endif