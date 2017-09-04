/*********************************************************************
** Author: Jared Parkinson
** Date: 10/26/2015
** Description: Assignment 5 - Week 5 - Project 5.a - Box.cpp
*********************************************************************/
#include <iostream>
#include <string>
#include "Box.hpp" //Header
using namespace std;

//Default Constructor - No Parameters
Box::Box()
{
	setHeight(1);
	setWidth(1);
	setLength(1);
};
//Constructor with Parameters
Box::Box(double h, double w, double l)
{
	setHeight(h);
	setWidth(w);
	setLength(l);
};

//Function Definition (implementation) section
/*************************************************************************
* Description: Setter Functions: Set the height, width & length of Box Obj
* Parameters: Accepts h, w, l single Parameter per name
* Return Value: None. Sets Data Members
**************************************************************************/
void Box::setHeight(double h)
{
	height = h;
}
void Box::setWidth(double w)
{
	width = w;
}
void Box::setLength(double l)
{
	length = l;
}
/***********************************************************************
* Description: Calculate Functions that give the Volume/Surface Area
* Parameters: Accepts none, uses private data members from Class
* Return Value: volume and surface area of Box Object
************************************************************************/
double Box::getVolume()
{
	double volume;
	volume = length*width*height;
	return volume;
}
double Box::getSurfaceArea()
{
	double areaHL, areaHW, areaWL, surfaceArea;
	areaHL = height*length;
	areaHW = height*width;
	areaWL = width*length;
	surfaceArea = (2 * areaHL) + (2 * areaHW) + (2 * areaWL);
	return surfaceArea;
};