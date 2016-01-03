#include <iostream>
#include <cmath>
#include "CartPoint.h"
#include "CartVector.h"

using namespace std;

//default constructor
CartPoint::CartPoint()
{
	x = 0.0;
	y = 0.0;
}

//initialize a specific point in CartPoint()
CartPoint::CartPoint(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}

/*NONMEMBER FUNCTIONS*/

//returns the distance between two Cartesian points
//by using the distance formula
double cart_distance(CartPoint p1, CartPoint p2)
{
	//initialize variables
	double distance;
	double magnitude;
	double xval;
	double yval;
	
	//distance formula steps
	xval = p2.x - p1.x;
	yval = p2.y - p1.y;
	magnitude = pow(xval, 2) + pow(yval, 2);
	distance = sqrt(magnitude);	
	
	return distance;
}

//compares x and y values of two cartesian points
//and returns true if they are the same
bool cart_compare(CartPoint p1, CartPoint p2)
{
	if (p1.x == p2.x && p1.y == p2.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*NONMEMBER OVERLOADED OPERATORS*/

//addition operator adds two cartesian points
//and returns the location of them
CartPoint operator+(const CartPoint& p1, const CartVector& v1)
{
	CartPoint location;
	location.x = v1.x + p1.x;
	location.y = v1.y + p1.y;
	
	return location;
}

//subtraction operator subtracts two cartesian points
//and returns them in the form of a vector
CartVector operator-(const CartPoint& p1, const CartPoint& p2)
{
	CartVector vec;
	vec.x = p1.x - p2.x;
	vec.y = p1.y - p2.x;
	
	return vec;
}

//outstream operator (<<) prints the
//(x,y) coordinate point
ostream& operator<<(ostream& out, const CartPoint& location)
{
	out << "(" << location.x << ", " << location.y << ")";
	return out;
}
