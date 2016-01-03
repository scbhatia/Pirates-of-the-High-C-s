#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include "CartPoint.h"

using namespace std;

class GameObject
{
	private:
	
		//private member variables
		int id_num;
	
	protected:
	
		//protected member variables
		CartPoint location;
		char display_code;
		char state;
		
	public:
	
		//constructors
		GameObject(char in_code, int in_id);
		GameObject(char in_code, int in_id, CartPoint in_loc);
		
		//public member functions
		CartPoint get_location();
		int get_id();
		virtual void show_status();
		virtual bool update() = 0;
		void drawself(char* grid);
		
		//destructor
		virtual ~GameObject();
};

#endif
