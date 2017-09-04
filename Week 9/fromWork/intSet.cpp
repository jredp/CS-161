  //////////////////// ** Author: Jared Parkinson 
 //   intSet.cpp   // *** Date: 11/23/2015
//////////////////// **** Desc: Week 9 - intSet.cpp  

#include "intSet.hpp"

	//Default Constructor
	intSet::intSet()
	{
		currentSize = 10;
		totalIntValues = 0;
		ptrToInt = new int[currentSize];	
	};
/*---------------------------------------------------------------------------------*/
	//DESTRUCTORRRR!!!!
	intSet::~intSet()
	{
		delete [] ptrToInt;		
	};
/*---------------------------------------------------------------------------------*/
	//Return # of values in intSet
	int intSet::size()
	{		
		return totalIntValues;
	};
/*---------------------------------------------------------------------------------*/
	//Bool return true if the IntSet contains no ints, else return false
	bool intSet::isEmtpy()
	{			
		if (totalIntValues == 0)
			return true;
		else
			return false;
	};
/*---------------------------------------------------------------------------------*/
	/*take an int parameter and return true if that value is in the IntSet,
		and return false otherwise*/
	int intSet::contains(int withinIntSet) const
	{
		bool isIn = false;
		for (int i=0; i<currentSize;++i)
			if (ptrToInt[i]==withinIntSet)
			{
				isIn=true; //1 : it is in array				
				//break;
			}		
		return isIn;
	};
/*---------------------------------------------------------------------------------*/
	//take int param, add that int to the IntSet, (if value not in int set)
	void intSet::add(int addToArray)
	{			
		if (!contains(addToArray) )// If int isn't in the array, do this //&& (currentSize == totalIntValues)
		{				
			totalIntValues++; //increment totalValues setA
			int *tempArray = new int[currentSize+1]; //create new array of size currentSize+1
			cout << "temp array should be at size: " << currentSize+1 << endl;
			
			//set last element to addToArray int parameter
			tempArray[currentSize] = addToArray; //last slot set to addToArray int
			cout << "temp last slot [currentSize] should be int: " << tempArray[currentSize] << endl;
						
			cout << "ptrToInt array should be at size: " << currentSize << endl;			
			
			for (int i=0; i<currentSize; ++i)
				tempArray[i] = ptrToInt[i]; //copy contents to temp
						
			delete [] ptrToInt; //free memory
			ptrToInt = new int[currentSize+1]; //new array of currentSize
			currentSize++; //now increment currentSize after copy
			cout << "currentSize after ++: " << currentSize << endl;
						
			for (int i=0; i<currentSize; ++i)
			{
				ptrToInt[i] = tempArray[i];		
				cout << "ptrToInt[i]: " << ptrToInt[i] << endl;
			}
			
			delete [] tempArray; //free old pointer memory
			//sort(ptrToInt, ptrToInt + currentSize);			
		};						
	};
/*---------------------------------------------------------------------------------*/
	/*take an int parameter and remove it from the IntSet (if that value --
	is in the IntSet) by shifting over all of the subsequent elements of the array*/	
	void intSet::remove(int removeMe)
	{		
		if (contains(removeMe))//if it contains the supplied int
		{
			int position;
			//find the position of int match		
			for (int i=0; i<currentSize; ++i)
			{
				if (ptrToInt[i] == ptrToInt[removeMe])
					position=i; //set position of removable int	
			};

			for (int i = 0; i<currentSize; ++i)
			{
				if (ptrToInt[i] == removeMe)
					ptrToInt[i] = NULL;
				else {};//do nothing
			}
			totalIntValues--; //decrement totalValues
		};
	};
/*---------------------------------------------------------------------------------*/
	/*setA.addAll(setB) should add to setA any values from setB that were --
	not already in setA (i.e. setA becomes the union of the two sets)*/
	void intSet::addAll(const intSet &setB)
	{
		int biggestArray = currentSize;
		//if (setB.currentSize < currentSize) //find largest array
		//	biggestArray = currentSize;
		//else
		//	biggestArray = setB.currentSize;
			
		for (int i=0; i<biggestArray; ++i)
		{
			for (int c = 0; c<currentSize; ++c)
			{
//				if (ptrToInt[i] == ptrToInt[removeMe])
//					position = i; //set position of removable int	
			};			
		};

	};
/*---------------------------------------------------------------------------------*/
	/*setA.removeDifferent(setB) should remove from setA any values that are --
	not also in setB (i.e. setA becomes the intersection of the two sets)*/
	void intSet::removeDifferent(const intSet &setB)
	{

	};
/*---------------------------------------------------------------------------------*/
	/*setA.removeSame(setB) should remove from setA any values that are also --
	in setB (i.e. setA becomes the relative complement of setA in setB)*/
	void intSet::removeSame(const intSet &setB)
	{

	};