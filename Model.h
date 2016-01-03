#ifndef MODEL_H
#define MODEL_H

#include "GameObject.h"
#include "Port.h"
#include "Dock.h"
#include "Sailor.h"
#include "View.h"

using namespace std;

class View;
class Model
{
	private:
		int time;
		
		//has a pointer in object_ptrs and other array
		GameObject* object_ptrs[10];
		int num_objects;
		Sailor* sailor_ptrs[3];
		int num_sailors;
		Dock* dock_ptrs[3];
		int num_docks;
		Port* port_ptrs[4];
		int num_ports;
		
		//copy constructor
		Model(Model &);
		
	public:
		//constructor
		Model();
		
		//destructor
		~Model();
	
		//public member functions
		Sailor* get_Sailor_ptr(int id_num);
		Port* get_Port_ptr(int id_num);
		Dock* get_Dock_ptr(int id_num);
		bool update();
		void display (View& view);
		void show_status();
		int get_time();
};

#endif
