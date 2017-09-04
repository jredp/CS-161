/*********************************************************************
** Author: Jared Parkinson
** Date: 11/04/2015
** Description: Assignment 6 - Week 6 - Project 6 - LineSegment.cpp
*********************************************************************/
#include <iostream>
#include "LineSegment.hpp"

using namespace std;

//Constructors - Create a LineSegment using two Points
LineSegment::LineSegment(Point point1, Point point2)
{
	setEnd1(point1);
	setEnd2(point2);
};

//Function Definition (implementation) section
/***************************************************************************
* Description: Setter Functions. Set the EndPoints of private Point Objects
* Parameters: Accepts a Point Object to set the either EndPoint
* Return Value: None. Set Functions.
****************************************************************************/
//Set data member pt1 xy
void LineSegment::setEnd1(Point point1)
{
	pt1.setXCoord(point1.getXCoord());
	pt1.setYCoord(point1.getYCoord());
};
//Set data member pt2 xy
void LineSegment::setEnd2(Point point2)
{
	pt2.setXCoord(point2.getXCoord());
	pt2.setYCoord(point2.getYCoord());
};

/*********************************************************************
* Description: Get Functions. Return the private Data Members pt1, pt2
* Parameters: Accepts none
* Return Value: Private Data Member pt1 or pt2
**********************************************************************/
//Getters
Point LineSegment::getEnd1()
{
	return pt1;
};
Point LineSegment::getEnd2()
{
	return pt2;
};

/*********************************************************************
* Description: Calculate Functions. Length of a line using distanceTo
*	/ Slope of a line using formula
* Parameters: Accepts none
* Return Value: double length of a line / double slope of a line
**********************************************************************/
//Calculations
double LineSegment::length()
{
	double length;
	length = pt1.distanceTo(pt2);
	return length;
};
double LineSegment::slope()
{
	double slope;
	slope = (pt2.getYCoord() - pt1.getYCoord())
		/ (pt2.getXCoord() - pt1.getXCoord());
	return slope;
};