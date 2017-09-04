/*********************************************************************
** Author: Jared Parkinson
** Date: 11/04/2015
** Description: Assignment 6 - Week 6 - Project 6 - Point.cpp
*********************************************************************/
#include <iostream>
#include <cmath>
#include "Point.hpp"

//Default Constructor
Point::Point()
{
	setXCoord(0);
	setYCoord(0);
};
//Constructor
Point::Point(double x, double y)
{
	setXCoord(x);
	setYCoord(y);
};
//Function Definition (implementation) section
/***************************************************************************
* Description: Setter Functions. Set the X and Y coordinates of Data Members
* Parameters: Accepts a double to set the X or the Y coordinate
* Return Value: None. Set Functions.
***************************************************************************/
//Setters
void Point::setXCoord(double setX)
{
	xcoord = setX;
};
void Point::setYCoord(double setY)
{
	ycoord = setY;
};

/*****************************************************
* Description: Get Functions. Returns xcoord/ycoord
* Parameters: Accepts none
* Return Value: Return the Data Members xcoord/ycoord
*****************************************************/
//Getters
double Point::getXCoord()
{
	return xcoord;
};
double Point::getYCoord()
{
	return ycoord;
};
/**********************************************************************
* Description: Calculate Function. Return the distance between 2 points
* Parameters: Accepts Point Object - Use as <pt>.distanceTo(pt1)
* Return Value: Distance from one Point to another
**********************************************************************/
//Calculate Function
double Point::distanceTo(const Point& objPoint) //Reference the object passed
{
	double distance;
	distance = sqrt(pow((objPoint.xcoord - xcoord), 2.0)
		+ pow((objPoint.ycoord - ycoord), 2.0));
	return distance;
};