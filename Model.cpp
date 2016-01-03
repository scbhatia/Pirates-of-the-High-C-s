#include <iostream>
#include "Model.h"
#include "CartPoint.h"

using namespace std;

//initial constructor initializes time and creates objects on the heap
Model::Model()
{
	time = 0;
	
	object_ptrs[0] = dock_ptrs[0] = new Dock(1, CartPoint(5,1));
	object_ptrs[1] = dock_ptrs[1] = new Dock(2, CartPoint(6,2));
	object_ptrs[2] = dock_ptrs[2] = new Dock(3, CartPoint(1,8));
	
	object_ptrs[3] = sailor_ptrs[0] = new Sailor(1, dock_ptrs[0]);
	object_ptrs[4] = sailor_ptrs[1] = new Sailor(2, dock_ptrs[1]);
	object_ptrs[5] = sailor_ptrs[2] = new Sailor(3, dock_ptrs[2]);
	
	object_ptrs[6] = port_ptrs[0] = new Port(1, CartPoint(1,20));
	object_ptrs[7] = port_ptrs[1] = new Port(2, CartPoint(20, 1));
	object_ptrs[8] = port_ptrs[2] = new Port(3, CartPoint(20, 20));
	object_ptrs[9] = port_ptrs[3] = new Port(4, CartPoint(7,2));
	
	//set num objects to 10, num sailors to 3, num ports to 4 and num docks to 3
	num_objects = 10;
	num_sailors = 3;
	num_ports = 4;
	num_docks = 3;
	
	cout << "Model default constructed" << endl;
}

//destructs model by deleting each object_ptrs
//frees the memory of all object_ptrs
Model::~Model()
{
	for (int i = 0; i < num_objects; i++)
	{
		delete object_ptrs[i];
	}
	
	cout << "Model destructed" << endl;
}

//iterates over sailor_ptrs and returns pointer to sailor object that has the id_num
//if theres no sailor object within id_num ID, return null
Sailor* Model::get_Sailor_ptr(int id_num)
{
	if (id_num > 0 && id_num <= num_sailors)
	{
		return sailor_ptrs[id_num - 1];
	}
	else
	{
		return NULL;
	}
}

//iterates over port_ptrs and returns pointer to port object that has the id_num
//if theres no port object within id_num ID, return null
Port* Model::get_Port_ptr(int id_num)
{
	if (id_num > 0 && id_num <= num_ports)
	{
		return port_ptrs[id_num - 1];
	}
	else
	{
		return NULL;
	}
}

//iterates over dock_ptrs and returns pointer to dock object that has the id_num
//if theres no dock object within id_num ID, return null
Dock* Model::get_Dock_ptr(int id_num)
{
	if (id_num > 0 && id_num <= num_ports)
	{
		return dock_ptrs[id_num - 1];
	}
	else
	{
		return NULL;
	}
}

//increments the time, iterates through object pointers and calls update for each object
bool Model::update()
{
	time++;
	int events = 0;
	for (int i = 0; i < num_objects; i++)
	{
		if (object_ptrs[i]->update())
		{
			events++;
		}
	}
	if (events > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//outputs the time and generates the view display for all GameObjects
void Model::display(View& view)
{
	cout << "Time: " << time << endl;
	view.clear();
	for (int i = 0; i < num_objects; i++)
	{
		view.plot(object_ptrs[i]);
	}
	
	view.draw();
}

//outputs status of gameobjects
void Model::show_status()
{
	for (int i = 0; i < num_objects; i++)
	{
		object_ptrs[i]->show_status();
	}
}

//returns time
int Model::get_time()
{
	return time;
}
