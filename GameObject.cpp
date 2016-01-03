#include <iostream>
#include "GameObject.h"

using namespace std;

//default constructor
//initializes display code, id num, and location
GameObject::GameObject(char in_code, int in_id)
{
	display_code = in_code;
	id_num = in_id;
	location.x = 0.0;
	location.y = 0.0;
	cout << "GameObject default constructed" << endl;
}

//object constructor
//initializes display code, id num, and location to their actual values
GameObject::GameObject(char in_code, int in_id, CartPoint in_loc)
{
	display_code = in_code;
	id_num = in_id;
	location.x = in_loc.x;
	location.y = in_loc.y;
	cout << "GameObject constructed" << endl;
}

//returns the location of the object
CartPoint GameObject::get_location()
{
	return location;
}

//returns the id num of the object
int GameObject::get_id()
{
	return this->id_num;
}

//returns the information about the object in this class
//gives the display code, id num, and location of the object
void GameObject::show_status()
{
	cout << display_code << " with ID " << id_num << " at location " << location;
}

//destructs GameObject
GameObject::~GameObject()
{
	cout << "GameObject destructed" << endl;
}

//puts display code and id number on grid in output
void GameObject::drawself(char* grid)
{
	*grid = this->display_code;
	*(grid+1) = '0' + this->id_num;
}
