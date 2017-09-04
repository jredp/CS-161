  //////////////////// ** Author: Jared Parkinson 
 //   IntSet.cpp   // *** Date: 11/23/2015
//////////////////// **** Desc: Week 9 - IntSet.cpp  

#include "IntSet.hpp"

/*---------------------------------------------------------------------------------*/
// Desc: Default Constructor
/*---------------------------------------------------------------------------------*/
	IntSet::IntSet()
	{
		currentSize = 10;
		totalIntValues = 0;
		ptrToInt = new int[currentSize];	
	};
/*---------------------------------------------------------------------------------*/
// Desc: Destructor
/*---------------------------------------------------------------------------------*/
	IntSet::~IntSet()
	{
		delete [] ptrToInt;		
	};
/*---------------------------------------------------------------------------------*/
// Desc: Return number of INT values in the IntSet
// Accepts: No Parameters
/*---------------------------------------------------------------------------------*/
	int IntSet::size()
	{		
		return totalIntValues;
	};
/*---------------------------------------------------------------------------------*/
// Desc: Return true if the IntSet contains no INTS, else return false
// Accepts: No Parameters
/*---------------------------------------------------------------------------------*/	
	bool IntSet::isEmtpy()
	{			
		if (totalIntValues == 0)
			return true;
		else
			return false;
	};
/*---------------------------------------------------------------------------------*/
// Desc: Take int param & return true if value is in the IntSet. Else, return false
// Accepts: INT Parameter
/*---------------------------------------------------------------------------------*/
	int IntSet::contains(int withinIntSet) const
	{
		bool isIn = false;
		for (int i=0; i<totalIntValues;++i)
			if (ptrToInt[i]==withinIntSet)
				isIn=true; //1 : it is in array		
		return isIn;
	};
/*---------------------------------------------------------------------------------*/
// Desc: Take int param & add it to IntSet if value isn't in IntSet. 
//		 Increase totalIntValues & place INT at that last value position.
// Accepts: INT Parameter
/*---------------------------------------------------------------------------------*/	
	void IntSet::add(int addToArray)
	{	
		if (!contains(addToArray))// If int not in array, do this
		{
			if (currentSize == totalIntValues)
			{				
				currentSize++; //increase size - array is full	
				int *tempArray = new int[currentSize]; //new temp holder array
				for (int i=0; i<totalIntValues; ++i)
					tempArray[i] = ptrToInt[i]; //copy only ints that matter
				delete [] ptrToInt; //free memory
				ptrToInt = tempArray;						
			}
			ptrToInt[totalIntValues] = addToArray; //set known int-free elem to param	
			totalIntValues++; //increment total due to add
			sort(ptrToInt, ptrToInt + totalIntValues); //sort to help other functions
		};						
	};	

/*---------------------------------------------------------------------------------*/
// Desc: Take int param & remove it from IntSet if value is in IntSet. 
//		 Decrease totalIntValues & place other INTs 1 slot to the left.
// Accepts: INT Parameter
/*---------------------------------------------------------------------------------*/
	void IntSet::remove(int removeMe)
	{	
		//if contains INT & that INT equals the last element slot
		if ((contains(removeMe)) && (ptrToInt[totalIntValues-1]==removeMe))
			totalIntValues--; //simply decrement int value

		else if (contains(removeMe))//if contains INT param
		{					
			for (int i=0; i<totalIntValues; ++i) //for every INT
				if (ptrToInt[i] > removeMe) //
					ptrToInt[i-1] = ptrToInt[i];
					totalIntValues--;
		};	
	};
/*---------------------------------------------------------------------------------*/
// Desc: Add to setA any values from setB that were	not already in setA.		
// Accepts: Called from setA - IntSet Object as setB Parameter
/*---------------------------------------------------------------------------------*/
	void IntSet::addAll(const IntSet &setB)
	{		
		for (int i=0; i<setB.totalIntValues; ++i)//for every INT in setB
			//add int to setA if not in setA (per add func contains)
			add(setB.ptrToInt[i]); 
	};
/*---------------------------------------------------------------------------------*/
// Desc: Remove setA INT that is not also contained in setB. Leave matches.	 
// Accepts: IntSet Object as setB Parameter
/*---------------------------------------------------------------------------------*/	
	void IntSet::removeDifferent(const IntSet &setB)
	{
		//loop per INTs in setA
		for (int i=0; i<totalIntValues; ++i) 
		{	
			//if setB doesn't contain setA INT comparison, remove
			if (!(setB.contains(ptrToInt[i])))
				remove(ptrToInt[i]);
		}
	};
/*---------------------------------------------------------------------------------*/
// Desc: Remove from setA INT that are also contained in setB. Leave differing INTS.	 
// Accepts: IntSet Object as setB Parameter
/*---------------------------------------------------------------------------------*/
	void IntSet::removeSame(const IntSet &setB)
	{
		//for every int (sorted) in setB
		for (int i=0; i<setB.totalIntValues; ++i)
			//if setA contains setB int, remove it from setA
			if (contains(setB.ptrToInt[i]))
				remove(setB.ptrToInt[i]);		
	};