  //////////////////// ** Author: Jared Parkinson 
 //   intSet.cpp   // *** Date: 11/23/2015
//////////////////// **** Desc: Week 9 - intSet.cpp  

#include "intSet.hpp"

	//Default Constructor
	intSet::intSet()
	{
		currentSize = 10;
		totalValues = 0;
		ptrToInt = new int[currentSize];	
	};
/*---------------------------------------------------------------------------------*/
	//DESTRUCTORRRR!!!!
	intSet::~intSet()
	{
		//delete [] ptrToInt; //FIX AFTER TEST
		//ptrToInt = 0;
	};
/*---------------------------------------------------------------------------------*/
	//Return # of values in intSet
	int intSet::size()
	{		
		return totalValues;
	};
/*---------------------------------------------------------------------------------*/
	//Bool return true if the IntSet contains no ints, else return false
	int intSet::isEmtpy()
	{			
		if (totalValues == 0)
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
		for (int i = 0; i < currentSize; ++i)
			if (ptrToInt[i] == withinIntSet)
			{
				isIn = true; //1 : it is in array				
				//break;
			}		
		return isIn;
	};
/*---------------------------------------------------------------------------------*/
	//take int param, add that int to the IntSet, (if value not in int set)
	void intSet::add(int addToArray)
	{			
		if (!contains(addToArray))// If int isn't in the array, do this
		{				
			totalValues++; //increment totalValues setA
			int *temp = new int[currentSize+1]; //temp holder for array
			//set last element to addToArray int parameter
			temp[currentSize+1] = addToArray; 

			delete [] ptrToInt; //free old pointer memory
			ptrToInt = new int[currentSize+1]; //array with NEW++ currentSize
			for (int i = 0; i<currentSize; ++i)
				temp[i] = ptrToInt[i]; //copy contents to temp
			currentSize++; //now increment currentSize after copy

			for (int i=0; i<currentSize; ++i)
				ptrToInt[i] = temp[i];			
			//sort(ptrToInt, ptrToInt + currentSize);
		};				
		cout << "ptr[0]: " << ptrToInt[0] << endl;
		cout << "ptr[1]: " << ptrToInt[1] << endl;
		cout << "ptr[2]: " << ptrToInt[2] << endl;
		cout << "ptr[3]: " << ptrToInt[3] << endl;
		cout << "ptr[4]: " << ptrToInt[4] << endl;
		cout << "ptr[5]: " << ptrToInt[5] << endl;
		cout << "ptr[6]: " << ptrToInt[6] << endl;
		cout << "ptr[7]: " << ptrToInt[7] << endl;
		cout << "ptr[8]: " << ptrToInt[8] << endl;
		cout << "ptr[9]: " << ptrToInt[9] << endl;
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
			totalValues--; //decrement totalValues
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