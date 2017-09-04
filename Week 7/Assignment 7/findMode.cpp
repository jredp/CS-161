/*****************************************************
** Author: Jared Parkinson
** Date: 11/11/2015
** Description: Assignment 7 - Week 7 - findMode.cpp
*****************************************************/
#include <vector>
#include <iostream>
#include <algorithm>

//include selective library methods used
using std::endl; using std::cout;
using std::vector; using std::sort;

//Function Prototype
vector<int> findMode(int array [], int length);

//int main() {		
//	int array[8] = {4,2,1,2,5,3,2,6}; //Test1: 2 higher	
//	int array[8] = {4,2,5,2,5,3,2,5};	//Test2: 2 & 5 equal
//	int array[8] = {2,1,5,4,3,8,6,7};	//Test3: 1 to 8 - 1 each	
//	findMode(array, 8);
//	system("PAUSE");
//	return 0;
//}

//Function Definition (implementation)
/****************************************************
* Description: Finds Mode in Array, outputs to Vector
* Parameters: Accepts (array, arraySize)
* Return Value: Vector with Mode(s)
****************************************************/
vector<int> findMode(int nums[], int length)
{	
	vector<int> returnVec; //return vector
	int freq = 0; //frequency
	sort(nums, nums+length); //PreSort-No sort Vector

	//Loop per array[size] - Find Highest Frequency Int
	for (int i=0; i<length; i++)
	{		
		int count = 1; //count of duplicate nums = 1
		//compare[i] next elem in line per loop /count++ each time see the same #
		for (int j=i+1; j<length; j++) 
			if (nums[i] == nums[j]) count++; 		
		//if count is higher, set freq to count
		if (count > freq) freq = count; 
	}

	//Loop same as above / compare freq to count2 / push matching ints
	for (int l=0; l<length; l++)
	{		
		int count2 = 1;
		for (int j=l+1; j<length; j++)
			if (nums[l] == nums[j]) count2++;
		//when count2 == freq, push vector elem - grow vector
		if (count2 == freq) returnVec.push_back(nums[l]);
	}
	// If max freq == 1, set all array elems to vector
	if (freq == 1)
	{		
		for (int a=0; a<length; a++)
			nums[a]=returnVec[a];					
	}

	//Test Output
	//cout << "Vec Size: " << returnVec.size() << endl;
	//int siz = returnVec.size();
	//for (int x=0; x<siz; x++) cout << "Vec Elem: " << returnVec[x] << endl;	
	
	return returnVec;
};