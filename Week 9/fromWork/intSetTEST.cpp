#include <iostream>

class intSet
{
	//Data Members
	int *ptrToInt;
	int currentSize = 0; //Updates when add() method creates bigger array
	int totalValues = 0; //Hold current number of values in the array	

	//Function Prototypes
	intSet();
	~intSet();
	size();
	isEmtpy();
	contains(int);
	remove();
	addAll();
	removeDifferent();
	removeSame();

	//default constructor
	intSet()
	{
		currentSize = 10;
		ptrToInt = new int [currentSize];
		for(count=0;count<currentSize;++count)
		{
			ptrToInt = 0;
		};
	}
	//DESTRUCTORRRR!!!!
	~intSet()
	{
		delete [] ptrToInt;
		ptrToInt = 0;
	}	

	//Return # of values in intSet
	size()
	{
		return totalValues;
	}; 

	//Bool return true if the IntSet contains no ints, else return false
	isEmtpy()
	{
		if(intSet)
			return false;
		else
			return true;
	};

	//take an int parameter and return true if that value is in the IntSet, and return false otherwise
	contains(int withinIntSet)
	{
		for(count=0;count<currentSize;++count)
		{
			if(ptrToInt[count] == withinIntSet)
				return true;
			else
				return false;
		};
	};

	//take int param, add that int to the IntSet, (if value not in int set)
	add(int addToArray)
	{
		for(count=0;count<currentSize;++count)
		{
			if(ptrToInt[count] == addToArray) //do nothing
			else
				ptrToInt = new int[currentSize+1];
		};
		for(count=0;count<currentSize;++count) //set totalValues cjecks if !=0
		{
			totalValues = 0
			if(ptrToInt[count] = 0) //update 
			else
				totalValues += 1;
		};
	};

	/*take an int parameter and remove it from the IntSet (if that value --
		is in the IntSet) by shifting over all of the subsequent elements of the array*/
	remove(int removeMe)
	{
		for(count=0;count<currentSize;++count)
		{
			if(ptrToInt[count] == removeMe)
				ptrToInt[count] = 0
			else
				ptrToInt = new int[currentSize+1];
		};
	};

	/*setA.addAll(setB) should add to setA any values from setB that were --
		not already in setA (i.e. setA becomes the union of the two sets)*/
	addAll();

	/*setA.removeDifferent(setB) should remove from setA any values that are --
		not also in setB (i.e. setA becomes the intersection of the two sets)*/
	removeDifferent();

	/*setA.removeSame(setB) should remove from setA any values that are also --
		in setB (i.e. setA becomes the relative complement of setA in setB)*/
	removeSame();
};


int main(){

	

	return 0;
}