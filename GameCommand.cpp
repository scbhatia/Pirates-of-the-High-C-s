#include <iostream>

#include "GameCommand.h"
#include "CartPoint.h"
#include "Sailor.h"

using namespace std;

//if user enters an s
//inputs parameters
//runs start sailing function
void do_sail_command(Model& model)
{
	int id;
	double x;
	double y;
	cin >> id >> x >> y;
	model.get_Sailor_ptr(id)->start_sailing(CartPoint(x,y));
	return;
}

//if user enters a g
//advances one tick
void do_go_command(Model& model)
{
	cout << "Advancing time one tick..." << endl;
	model.update();
	model.show_status();
	return;
}

//if user enters a r
//advance one time step and update each object
//runs until next event reached or 5 ticks
//(doesn't work after d? and gives segfault error?)
void do_run_command(Model& model)
{
	cout << "Advancing to next event or 5 ticks" << endl;
	bool events = model.update();
	
	for (int i = 0; i < 4; i++)
	{
		if (model.update())
		{
			break;
		}
	}
	model.show_status();
}

//if user enter a p
//inputs parameters and runs start_supplying function
void do_port_command(Model& model)
{
	int ID1;
	int ID2;
	cin >> ID1 >> ID2;
	model.get_Sailor_ptr(ID1)->start_supplying(model.get_Port_ptr(ID2));
	return;
}

//if user enters h
//inputs parameters and runs start_hiding function 
void do_hide_command(Model& model)
{
	int id;
	cin >> id;
	model.get_Sailor_ptr(id)->start_hiding();
	return;
}

//if user enters a
//runs anchor function
void do_anchor_command(Model& model)
{
	int id;
	cin >> id;
	model.get_Sailor_ptr(id)->anchor();
	return;
}

void do_list_command(Model& model)
{
	model.show_status();
}

//user enters d
//inputs parameters
//runs start_docking function
void do_dock_command(Model& model)
{
	int ID1;
	int ID2;
	cin >> ID1 >> ID2;
	model.get_Sailor_ptr(ID1)->start_docking(model.get_Dock_ptr(ID2));
	return;
}
