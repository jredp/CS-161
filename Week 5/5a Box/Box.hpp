/*********************************************************************
** Author: Jared Parkinson
** Date: 10/26/2015
** Description: Assignment 5 - Week 5 - Project 5.a - Box.hpp
*********************************************************************/
//Include Guard
#ifndef BOX_HPP
#define BOX_HPP

#include <string>

//Class Declaration (Interface)
class Box 
{
	private: //Only used within this class
		double height, width, length; //Private Data Members

	public: //Can use outside class
		//Default Constructor
		Box();
		//Constructor with Params
		Box(double h, double w, double l);
		
		//Function Prototypes - (Declare without body)
		// Setters
		void setHeight(double h);
		void setWidth(double w);
		void setLength(double l);

		// Calculate Functions	
		double getVolume();
		double getSurfaceArea();
};
//End Guard
#endif