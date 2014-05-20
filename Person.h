#ifndef PERSON_H
#define PERSON_H

#include <iostream>

#include "Game_Object.h"
#include "Candy_Mine.h"
#include "Tower.h"

class Model;	// Person now depends on Model for inspection
				// Forward declare Model to avoid circular dependancy

class Person: public Game_Object {
	public:
		// Constructors
		Person();
		Person(char in_code);
		Person(char in_code, int id_in, C_Point in_loc);
		virtual ~Person();

		bool start_moving(C_Point dest);
		bool stop();
		void show_status();
		bool is_alive();
		void take_hit(int attack_strength);

		virtual bool start_attack(Person* target);
		virtual bool start_mining(Candy_Mine* inputMine, Tower* inputHome);
		virtual bool start_inspecting(Model &model);

		void save(std::ofstream &file);
		void restore(std::ifstream &file, Model &model);

	protected:
		bool update_location();
		void setup_destination(C_Point dest);

	private:
		double speed;
		C_Point destination;
		C_Vector delta;

		int health;
};

#endif