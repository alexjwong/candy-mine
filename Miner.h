#ifndef MINER_H
#define MINER_H

#include <iostream>
#include "Person.h"

class Model;

class Miner: public Person {
	public:
		// Constructors
		Miner();
		Miner(int in_id, C_Point in_loc);
		~Miner();

		bool update();
		bool start_mining(Candy_Mine* inputMine, Tower* inputHome);
		void show_status();

		void save(std::ofstream &file);
		void restore(std::ifstream &file, Model &model);


	private:
		double amount;
		Candy_Mine* mine;
		Tower* home;

};

#endif