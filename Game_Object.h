#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <iostream>
#include <fstream>

#include "C_Point.h"
#include "C_Vector.h"

class Model;

class Game_Object {

	public:
		// Constructors
		Game_Object();
		Game_Object(char in_code);
		Game_Object(char in_code, int in_id, C_Point in_loc);
		virtual ~Game_Object();

		C_Point get_location();
		int get_id();
		virtual void show_status();
		void drawself(char * ptr);
		virtual bool update() = 0;
		virtual bool is_alive();
		
		virtual void save(std::ofstream &file);
		virtual void restore(std::ifstream &file, Model &model);

	private:
		int id_num;

	protected:
		C_Point location;
		char display_code;
		char state;
};

// Returns the Cartesian distance between p1 and p2
double C_distance(C_Point p1, C_Point p2);

#endif