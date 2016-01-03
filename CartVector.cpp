#include <iostream>
#include <vector>

#include "CartVector.h"
#include "CartPoint.h"

using namespace std;

/*CONSTRUCTORS*/

//default constructor
CartVector::CartVector()
{
	x = 0.0;
	y = 0.0;
}

//initalize default constructor to specific values		
CartVector::CartVector(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}

/*NONMEMBER OVERLOADED OPERATORS*/

//multiplication operator multiplies the Cartesian vector
//by a scalar value and returns the new vector
CartVector operator*(const CartVector& v1, const double d)
{
	CartVector vec;
	vec.x = v1.x * d;
	vec.y = v1.y * d;
	
	return vec;
}

//division operator divides the Cartesian vector
//by a scalar and returns the new vector
CartVector operator/(const CartVector& v1, const double d)
{
	CartVector vec;
	//if the scalar is zero
	//returns the original vector
	if (d == 0)
	{
		vec.x = v1.x;
		vec.y = v1.y;
	}
	else
	{
		vec.x = v1.x / d;
		vec.y = v1.y / d;
	}
	
	return vec;
}

//outstream operator (<<) prints the 
//Cartesian vector
ostream& operator<<(ostream& out, const CartVector& vec)
{
	out << "<" << vec.x << ", " << vec.y << ">" << endl;
	
	return out;
}
