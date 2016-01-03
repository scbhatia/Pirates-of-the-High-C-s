#include <iostream>

#include "Port.h"

using namespace std;

//default constructor initializes member variables to original values
Port::Port(): GameObject('P', 0)
{
	state = 'f';
	inventory = 500;
	cout << "Port default constructed" << endl;
}

//initializes id number to in id, location to in loc, and other values are listed above
//inherits values from gameobject, which gives display code
Port::Port(int in_id, CartPoint in_loc): GameObject('P', in_id, location)
{
	location = in_loc;
	state = 'f';
	inventory = 500;
	cout << "Port Constructed" << endl;
}

//returns true of the port has no more supplies
//returns false if there is inventory left
bool Port::is_empty()
{
	if (inventory == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//if inventory contains more than amount needed to supply
//subtracts amount from inventory
double Port::provide_supplies(double amount_to_provide)
{
	if (inventory >= amount_to_provide)
	{
		inventory = inventory - amount_to_provide;
		return amount_to_provide;
	}
	//otherwise inventory is assigned to amount to supply
	//and inventory is then given a value of zero
	else
	{
		amount_to_provide = inventory;
		inventory = 0;
		return amount_to_provide;
	}
}

//updates the state and display code
bool Port::update()
{
	//if state is not e and port is empty
	//state is changed back to e and display code is p
	//returns true
	if (state == 'f' && is_empty())
	{
		state = 'e';
		display_code = 'p';
		cout << "Port " << get_id() << " has been depleted." << endl;
		return true;
	}
	
	//otherwise returns false
	else
	{
		return false;
	}
}

//prints out status of an object
//using GameObject to give information about object
void Port::show_status()
{
	cout << "Port status: ";
	GameObject::show_status();
	cout << " Contains " << inventory << "." << endl;
}

//destructs port
Port::~Port()
{
	cout << "Port destructed." << endl;
}
