/*********************************************************************
** Author: Jared Parkinson
** Date: 11/04/2015
** Description: Assignment 6 - Week 6 - Project 6 - main.cpp
*********************************************************************/
#include <iostream>
#include "LineSegment.hpp"

using namespace std;
int main()
{
	//Point Test
	Point p1(-1.5, 1.0); Point p2(1.5, 2.0);
	double dist = p1.distanceTo(p2);
	cout << "Distance: " << dist << endl;

	//LineSegment Test
	LineSegment ls1(p1, p2);
	double length = ls1.length();
	double slope = ls1.slope();
	cout << "Length: " << length << endl;
	cout << "Slope: " << slope << endl;
	
	//EndPoints Test
	Point ept1 = ls1.getEnd1();
	Point ept2(1.4, 2.3);
	cout << "EndPoint1 PreTest: (" << ept1.getXCoord() << ", " << ept1.getYCoord() << ")" << endl;
	ls1.setEnd1(ept2);
	cout << "EndPoint1 PostTest: (" << ept2.getXCoord() << ", " << ept2.getYCoord() << ")" << endl;
	
	//system("PAUSE");
	return 0;
}