/*********************************************************************
** Author: Jared Parkinson
** Date: 11/04/2015
** Description: Assignment 6 - Week 6 - Project 6 - LineSegment.hpp
*********************************************************************/
#include <iostream>
#include "Point.hpp"

#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP

//Class Declaration (Interface)
class LineSegment
{
private:
	//Create 2 point objects from Point class
	Point pt1;
	Point pt2;

public:
	//Constructor - No default requested / Accepts 2 points
	LineSegment(Point, Point);

	//Setters - Sets endpoint x and y per Point
	void setEnd1(Point); 
	void setEnd2(Point);

	//Getters
	Point getEnd1();
	Point getEnd2();

	//Calculations
	double length();
	double slope();
};

//End Guard
#endif