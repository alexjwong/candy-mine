#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <list>

#include "Game_Object.h"
#include "Candy_Mine.h"
#include "Tower.h"
#include "View.h"
#include "Miner.h"
#include "Warrior.h"
#include "Inspector.h"
#include "Input_Handling.h"

class Model {
	public:
		Model();
		~Model();

		Person * get_Person_ptr(int id);
		Candy_Mine * get_Candy_Mine_ptr(int id);
		Tower * get_Tower_ptr(int id);

		std::list<Candy_Mine*> get_Candy_Mine_list();		// Return a list of the Candy Mines

		void new_object(int in_id, C_Point in_loc, char type);		// Create a new object

		bool update();								// Updates all objects
		void display(View &view);					// Diplays the board
		void show_status();							// Prints the status of all objects
	
	private:
		int time;

		std::list<Game_Object*> object_ptrs;
		std::list<Game_Object*> active_ptrs;

		std::list<Person*> person_ptrs;
		std::list<Candy_Mine*> mine_ptrs;
		std::list<Tower*> tower_ptrs;
};

#endif