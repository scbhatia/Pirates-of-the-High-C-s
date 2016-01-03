#ifndef DOCK_H
#define DOCK_H

#include "GameObject.h"
#include "Sailor.h"

using namespace std;

class Sailor;

class Dock: public GameObject
{
	private:
	
		//private member variables
		double berths;
		
	public:
	
		//constructors
		Dock(); 
		Dock(int in_id, CartPoint in_loc); 
		
		//public member functions
		bool dock_boat(Sailor* sailor_to_dock);
		bool set_sail(Sailor* sailor_to_sail);
		bool update();
		void show_status();
		
		~Dock(); //destructor
};

#endif
