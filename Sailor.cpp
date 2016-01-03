#include <iostream>
#include <cmath>
#include "Sailor.h"

using namespace std;

//default constructor sets all values to initial values
Sailor::Sailor(): GameObject('S', 0)
{
	this->health = 25;
	this->size = 15;
	this->hold = 100;
	this->cargo = 0;
	this->port = NULL;
	this->dock = NULL;
	this->hideout = NULL;
	this->state = 'a';
	destination = CartPoint();
	cout << "Sailor Default Constructed" << endl;
}

//constructor sets id number and initial location of object using supplied values
//remainder of members same as above
//change state to h for hidden (for whatever reason keeps giving seg fault every time i do)
//commented out
Sailor::Sailor(int in_id, Dock* hideout): GameObject('S', in_id, hideout->get_location())
{
	health = 25;
	size = 15;
	hold = 100;
	cargo = 0;
	this->hideout = hideout;
	hideout->get_location();
	state = 'h';
	destination = CartPoint();
	cout << "Sailor constructed" << endl;
}

//updates objects location while moving
bool Sailor::update_location()
{
	//find distance between destination and location coordinates
	CartVector v;
	v.x = destination.x - location.x;
	v.y = destination.y - location.y;
	//if the absolute value of the distance is less than delta (the calculated travel step)
	//arrive at location and print "I'm there!"
	//return true
	if ((fabs(v.x) <= fabs(delta.x)) && (fabs(v.y) <= fabs(delta.y)))
	{
		location.x = destination.x;
		location.y = destination.y;
		cout << display_code << get_id() << ": I'm there!" << endl;
		return true;
	}
	//otherwise increase location by delta
	//print "Just keep sailing..."
	//return false;
	else
	{
		location.x = location.x + delta.x;
		location.y = location.y + delta.y;
		cout << display_code << get_id() << ": Just keep sailing..." << endl;
		return false;
	}
}

//set up the object to start moving towards the destination
void Sailor::setup_destination(CartPoint dest)
{
	destination = dest;
	delta = (destination - location) * (get_speed() / cart_distance(destination, location));
}

//update the status of the object at each time unit
//returns true every time the status changes
bool Sailor::update()
{
	//use a switch statement to update
	switch(state)
	{
		//a is for anchored
		//does nothing and stays in state
		case 'a':
		{
			return false;
		}
		
		//s is for sailing to a destination
		//takes a step upon calling update location
		//return true if object arrives
		case 's':
		{
			if (!update_location())
			{
				return false;
			}
			else
			{
				state = 'a';
				return true;
			}
		}
		break;
		
		//o is for outbound to port
		//call update location to take a step
		//if arrived change state and return true
		case 'o':
		{
			if (!update_location())
			{
				return false;
			}
			else
			{
				cout << display_code << get_id() << ": Starting to supply at a port" << endl;
				state = 'l';
				return true;
			}
		}
		break;
		
		//i is for inbound sailing to dock
		//call update location to take a step
		//return true if arrived and change state
		case 'i':
		{
			if (!update_location())
			{
				return false;
			}
			else
			{
				state = 'u';
				return true;				
			}
		}
		break;
		
		//l is for loading
		case 'l':
		{
			//if cargo value is equal to maximum value sailor can hold
			//change state and state that boat is full
			//return true
			if (cargo == hold)
			{
				state = 'a';
				cout << display_code << get_id() << ": My boat is filled up. Send me to a dock to unload. Dropping anchor." << endl;
				return true;
			}
			//otherwise change state to a
			//state port has no more supplies
			//return true
			else
			{
				if (port->is_empty())
				{
					state = 'a';
					cout << display_code << get_id() << ": This port has no more supplies for me. Dropping anchor." << endl;
					return true;
				}
				//otherwise add supplies to cargo
				else
				{
					double amount_to_provide = 50.0;
					double supplies = port->provide_supplies(amount_to_provide);
					cargo = cargo + supplies;
					cout << display_code << get_id() << ": My new cargo is " << get_cargo() << endl;
					if (cargo > hold)
					{
						cargo = hold;
					}
				}
			}
		}
		break;
		
		//u is for unloading at a dock
		//if the boat can dock, change state to d
		//and change values if cargo > 0
		//return true
		case 'u':
		{
			if (dock->dock_boat(this))
			{
				state = 'd';
				if (cargo > 0)
				{
					hold = hold + 20;
					size = size + 5;
					cargo = 0;
				}
				cout << display_code << get_id() << ": I am unloading at the dock" << endl;
				return true;
			}
			
			//otherwise state that the dock is full
			//change state to t
			//return true
			else
			{
				state = 't';
				cout << display_code << get_id() << ": Help! My dock is full" << endl;
				return true;
			}
			
			//default return false
			return false;
		}
		break;
		
		//d is for docked 
		//sailor does nothing and stays in state
		//return false
		case 'd':
		{
			return false;
		}
		break;
		
		//h is for hiding
		//if location is reached, change location to a
		//return true
		case 'h':
		{
			if (is_hidden())
			{
				cout << display_code << get_id() << ": Is going to hide at Dock " << dock->get_id() << endl;
				state = 'a';
				return true;
			}
			//otherwise return false
			else
			{
				return false;
			}
		}
		
		//t is for trouble
		//does nothing and stays in state
		//returns false
		case 't':
		{
			return false;
		}
		
		//by default, returns false
		default:
		{
			return false;
		}
	}
}

//returns size
double Sailor::get_size()
{
	return size;
}

//returns cargo
double Sailor::get_cargo()
{
	return cargo;
}

//tells sailor to start sailing to given destination
//calls setup destination and changes state to s
//if state is d, release sailor
void Sailor::start_sailing(CartPoint dest)
{
	if (state == 'd')
	{
		dock->set_sail(this);
	}
	destination = dest;
	setup_destination(destination);
	state = 's';
	cout << "Sailing " << get_id() << " to"  << destination << endl;
	cout << display_code << " " << get_id() << ": On my way" << endl;
}

//tells sailor to start supplying at given port
//set port to dest port and make it new destination
//change state to o
void Sailor::start_supplying(Port* destPort)
{
	port = destPort;
	setup_destination(destPort->get_location());
	state = 'o';
	cout << "Sailor " << get_id() << " supplying at Port " << destPort->get_id() << " and going to port " << destPort->get_id() << endl;
	cout << display_code << get_id() << ": Supplies here I come" << endl;
}

//tells sailor to start hiding at hideout location
//calls setup destination and changes state to h
void Sailor::start_hiding()
{
	setup_destination(hideout->get_location());
	state = 'h';
	cout << "Sailor " << get_id() << " hiding " << hideout->get_id() << endl;
	cout << display_code << get_id() << ": Off to hide." << endl;
}

//if sailor is at destination
//return true
bool Sailor::is_hidden()
{
	if (destination.x == location.x && destination.y == location.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//if sailor is hidden, allow sailor to set sail
//set new dock equal to destination dock
//change state to i
//print statements
void Sailor::start_docking(Dock* destDock)
{
	if (is_hidden())
	{
		destDock->set_sail(this);
	}
	dock = destDock;
	setup_destination(destDock->get_location());
	state = 'i';
	cout << "Sailor " << get_id() << " sailing to Dock " << dock->get_id() << endl;
	cout << display_code << get_id() << ": Off to dock" << endl;
}

//change state to a and print statements saying that anchor is being dropped
void Sailor::anchor()
{
	state = 'a';
	cout << "Stopping " << get_id() << "." << endl;
	cout << display_code << get_id() << ": Dropping anchor" << endl;
}

//prints the status of the sailor in each state
void Sailor::show_status()
{
	cout << "Sailor status: " << display_code << " with ID " << get_id() << " at location " << this->get_location();
	switch(this->state)
	{
		//a is for anchored
		case 'a':
		{
			if (!is_hidden())
			{
				cout << " is anchored. Has a size of: " << get_size() << ", cargo of: " << get_cargo() << ", hold of: " << hold << ", and health of: " << health << endl;	
			}
			else
			{
				cout << " is anchored (and hiding). Has a size of: " << get_size() << ", cargo of: " << get_cargo() << ", hold of: " << hold << ", and health of: " << health << endl;
			}
		}
		break;
		
		//s is for sailing
		case 's':
		{
			cout << " has a speed of: " << get_speed() << " and is heading to: " << this->destination << endl;
		}
		break;
		
		//o is for outbound
		case 'o':
		{
			cout << " is outbound to Port: " << port->get_id() << " with a speed of " << get_speed() << endl;
		}
		break;
		
		//i is for inbound
		case 'i':
		{
			cout << " is inbound to Dock: " << dock->get_id() << "with a speed of " << get_speed() << endl;
		}
		break;
		
		//l is for loading
		case 'l':
		{
			cout << " is supplying at Port " << port->get_id() << endl;
		}
		break;
		
		//u is for unloading
		case 'u':
		{
			cout << " is unloading at Dock " << dock->get_id() << endl;
		}
		break;
		
		//d is for docked
		case 'd':
		{
			cout << " is docked at Dock " << dock->get_id() << endl;
		}
		break;
		
		//h is for hiding
		case 'h':
		{
			cout << display_code << get_id() << ": Is going to hide at Dock " << hideout->get_id() << endl;
		}
		break;
		
		//t is for trouble
		case 't':
		{
			cout << " is in trouble " << get_id() << endl;
		}
		break;
	}
}

//return speed
double Sailor::get_speed()
{
	return (size - (cargo*.1));
}

//destruct sailor
Sailor::~Sailor()
{
	cout << "Sailor destructed." << endl;
}
