#ifndef VIEW_H
#define VIEW_H

#include "Model.h"
#include "GameObject.h"
#include "CartPoint.h"

const int view_maxsize = 20;

class View
{
	public:
		
		//constructors
		View();
		
		//destructors
		~View();
		
		//public member functions
		void clear();
		void plot(GameObject* ptr);
		void draw();
		
	private:
		
		//private member variables
		int size;
		double scale;
		CartPoint origin;
		
		//private member functions and dynamic arrays
		char grid[view_maxsize][view_maxsize][2];
		bool get_subscripts(int &ix, int &iy, CartPoint location);
		
};

#endif
