#ifndef CARTPOINT_H
#define CARTPOINT_H

#include "CartVector.h"

using namespace std;

class CartPoint
{
	public:
	
		//public member variables
		double x;
		double y;
		
		//constructors
		CartPoint();
		CartPoint(double in_x, double in_y);
};

//public nonmember functions
double cart_distance(CartPoint p1, CartPoint p2);
bool cart_compare(CartPoint p1, CartPoint p2);

//overloaded nonmember operators
CartPoint operator+(const CartPoint& p1, const CartVector& v1);
CartVector operator-(const CartPoint& p1, const CartPoint& p2);
ostream& operator<<(ostream& out, const CartPoint& location);

#endif
