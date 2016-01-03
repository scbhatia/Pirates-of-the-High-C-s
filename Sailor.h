#ifndef SAILOR_H
#define SAILOR_H

#include <iostream>
#include "GameObject.h"
#include "Port.h"
#include "Dock.h"
#include "CartVector.h"

using namespace std;

class Dock;
class Port;

class Sailor: public GameObject
{
	friend class Dock;
	friend class Port;
	private:
	
		//private member variables
		double health;
		double size;
		double hold;
		double cargo;
		CartPoint destination;
		CartVector delta;
		Port* port;
		Dock* dock;
		Dock* hideout;
		
		//private member functions
		bool update_location();
		void setup_destination(CartPoint dest);
		
	public:
	
		//constructors
		Sailor();
		Sailor(int in_id, Dock* hideout);
		
		//public member functions
		bool update();
		double get_size();
		double get_cargo();
		void start_sailing(CartPoint dest);
		void start_supplying(Port* destPort);
		void start_hiding();
		bool is_hidden();
		void start_docking(Dock* destDock);
		void anchor();
		void show_status();
		double get_speed();
		
		//destructor
		~Sailor();
};

#endif
