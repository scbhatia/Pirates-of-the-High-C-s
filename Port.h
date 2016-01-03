#ifndef PORT_H
#define PORT_H

#include <iostream>
#include "GameObject.h"

using namespace std;

class Port: public GameObject
{
	private:
		
		//private member variables
		double inventory;
		
	public:
		
		//constructors
		Port();
		Port(int in_id, CartPoint in_loc);
		
		//public member functions
		bool is_empty();
		double provide_supplies(double amount_to_provide = 50.0);
		bool update();
		void show_status();	
		
		//destructor
		~Port();
};

#endif
