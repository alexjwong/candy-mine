#ifndef INSPECTOR_H
#define INSPECTOR_H

#include <iostream>
#include <list>

#include "Person.h"

class Model;

class Inspector : public Person {
	public:
		Inspector();
		Inspector(int in_id, C_Point in_loc);
		~Inspector();

		bool update();
		void show_status();
		bool start_inspecting(Model &model);

		void save(std::ofstream &file);
		void restore(std::ifstream &file, Model &model);

	private:
		std::list<Candy_Mine*> outbound_mine_ptrs;	// Local list of Candy_Mines (to inspect)
		std::list<Candy_Mine*> inbound_mine_ptrs;	// Reverse order for return trip
		std::list<int> outbound_amounts;	// List of OUTBOUND amounts in mines

		C_Point original_location;

};

#endif