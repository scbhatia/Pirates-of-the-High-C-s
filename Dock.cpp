#include <iostream>

#include "Dock.h"

using namespace std;

//default destructor initializes values to their initial value
Dock::Dock():GameObject('d', 0)
{
	state = 'u';
	berths = 30;
	cout << "Dock default constructed" << endl;
}

//constructor initializes id number to in id, location to in loc, and remainder of variables assigned as above
Dock::Dock(int in_id, CartPoint in_loc):GameObject('d', in_id, location)
{
	state = 'u';
	berths = 30;
	location = in_loc;
	cout << "Dock constructed" << endl;
}

//tries to dock the sailor if there is space on the dock
bool Dock::dock_boat(Sailor* sailor_to_dock)
{
	//if the amount of space on the dock is greater than or equal to the size of the sailor
	//decreases berths and docks boat
	//returns true
	if (berths >= sailor_to_dock->get_size())
	{
		berths = berths - sailor_to_dock->get_size();
		return true;
	}
	//otherwise returns false
	else
	{
		return false;
	}
}

//tries to release the sailor if the sailor emptied his boat
bool Dock::set_sail(Sailor* sailor_to_sail)
{
	//if the sailor can leave since the boat has been emptied
	//berths increases by the original size of the sailor
	//return true;
	if (sailor_to_sail-> is_hidden())
	{
		berths = berths + sailor_to_sail->get_size();
		return true;
	}
	//otherwise return false
	else
	{
		return false;
	}
}

//updates the status of the dock
bool Dock::update()
{
	//if there are no more berths and state is not p
	//set state to p and display code to D
	//print that dock is depleted
	//returns true
	if (berths == 0 && state != 'p')
	{
		state = 'p';
		display_code = 'D';
		
		cout << "Dock " << get_id() << " is depleted" << endl;
		return true;
	}
	
	//there are still berths available and the state is p
	//keep display code at d and state at u
	//returns false
	else if (berths != 0 && state == 'p')
	{
		state = 'u';
		display_code = 'd';
		
		return false;
	}
	return false;
}

//prints the status of the dock with all of its information
void Dock::show_status()
{
	cout << "Dock Status: ";
	GameObject::show_status();
	cout << " has a berth of " << berths << endl;
}


//destructs dock
Dock::~Dock()
{
	cout << "Dock destructed." << endl;
}
