#ifndef CANDY_MINE_H
#define CANDY_MINE_H

#include <iostream>

#include "Game_Object.h"

class Game_Object;

class Model;

class Candy_Mine: public Game_Object {

	public:
		// Constructors
		Candy_Mine();
		Candy_Mine(int inputId, C_Point inputLoc);
		~Candy_Mine();

		bool is_empty();
		double dig_candy(double amount_to_dig = 35.0);
		bool update();
		void show_status();
		double get_Candy_amount();
		
		void save(std::ofstream &file);
		void restore(std::ifstream &file, Model &model);

	private:
		double amount;

};

#endif