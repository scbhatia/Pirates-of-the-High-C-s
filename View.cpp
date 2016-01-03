#include <iostream>
#include <iomanip>
#include <cmath>

#include "View.h"
#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"

using namespace std;

//default constructor initializes grid
View::View()
{
	size = 11;
	scale = 2;
	origin = CartPoint(0,0);
}

//sets all cells to the background pattern shown
void View::clear()
{
	for (int x = 0; x < view_maxsize; x++)
	{
		for (int y = 0; y < view_maxsize; y++)
		{
			grid[x][y][0] = '.';
			grid[x][y][1] = ' ';
		}
	}
}

//plots the objects in the proper places using get_subscripts
//if get_subscripts are valid calls drawself() method from GameObject
//if something is already in that spot, characters replaced by * and a space
void View::plot(GameObject* ptr)
{
	int ix;
	int iy;
	
	if (get_subscripts(ix, iy, ptr->get_location()))
	{
		if (grid[ix][iy][0] != '.')
		{
			grid[ix][iy][0] = '*';
			grid[ix][iy][1] = ' ';
		}
		else
		{
			ptr->drawself(grid[ix][iy]);
		}
	}
}

void View::draw()
{
	for (int y = (size-1); y >= 0; y--)
	{
		if ((y%(int)scale) == 0)
		{
			cout << setw(2) << left << (y*scale);
		}
		else 
		{
			cout << "  ";
		}

		for (int x = 0; x < size; x++)
		{
			cout << grid[x][y][0];
			cout << grid[x][y][1];
		}

		cout << endl;
	}

	cout << " ";
	for (int i = 0; i < size; i++)
	{
		if ((i%(int)scale)==0)
		{
			cout << setw(4) << left << i*scale;
		}
	}

	cout << left << endl;
}

//calculates the column and row subscripts that coorespond to location
//calculates by finding distance from origin/scale
//if object is not within display, print that and return false
//otherwise return true
bool View::get_subscripts(int &ix, int &iy, CartPoint location)
{
	CartVector newvec = (location - origin) / scale;
	ix = (int)newvec.x;
	iy = (int)newvec.y;
	
	if (ix < 0 || ix > size || iy < 0 || iy > size)
	{
		cout << "An object is outside the display" << endl;
		return false;
	}
	else
	{
		return true;
	}
}

//destructs view
View::~View()
{
	cout << "View deconstructed." << endl;
}
