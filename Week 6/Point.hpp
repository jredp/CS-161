/*********************************************************************
** Author: Jared Parkinson
** Date: 11/04/2015
** Description: Assignment 6 - Week 6 - Project 6 - Point.hpp
*********************************************************************/
#include <iostream>
using namespace std;

#ifndef POINT_HPP 
#define POINT_HPP

//Class Declaration (Interface)
class Point
{
private: //Data Members
	double xcoord, ycoord;

public:
	//Constructor Prototypes
	Point();
	Point(double, double);

	//Function Prototypes
	//Setters
	void setXCoord(double);
	void setYCoord(double);

	//Getters
	double getXCoord();
	double getYCoord();

	//Calculations
	double distanceTo(const Point&);
};
//End Guard
#endif