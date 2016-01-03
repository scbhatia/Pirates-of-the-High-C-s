#ifndef CARTVECTOR_H
#define CARTVECTOR_H

#include <iostream>
using namespace std;

class CartVector
{
	public:
	
		//public member variables
		double x;
		double y;
		
		//constructors
		CartVector();
		CartVector(double in_x, double in_y);
};

//overloaded nonmember operators
ostream& operator<<(ostream& out, const CartVector& vec);
CartVector operator*(const CartVector& v1, const double d);
CartVector operator/(const CartVector& v1, const double d);

#endif
