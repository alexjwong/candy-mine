#ifndef WARRIOR_H
#define WARRIOR_H

#include <iostream>
#include "Person.h"

class Model;

class Warrior: public Person {
	public:
		Warrior();
		Warrior(int in_id, C_Point in_loc);
		~Warrior();

		bool start_attack(Person* in_target);
		bool update();
		void show_status();

		void save(std::ofstream &file);
		void restore(std::ifstream &file, Model &model);

	private:
		int attack_strength;
		double range;
		Person * target;
};

#endif