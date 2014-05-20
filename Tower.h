#ifndef TOWER_H
#define TOWER_H

#include <iostream>

#include "Game_Object.h"

class Model;

class Game_Object;

class Tower: public Game_Object {
	public:
		// Constructors
		Tower();
		Tower(int inputId, C_Point inputLoc);
		~Tower();

		void deposit_candy(double deposit_amount);
		bool update();
		void show_status();

		void save(std::ofstream &file);
		void restore(std::ifstream &file, Model &model);

	private:
		double amount;
};

#endif