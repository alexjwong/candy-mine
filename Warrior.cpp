#include "Warrior.h"
#include "math.h"

Warrior::Warrior() : Person('W'){
	attack_strength = 2;
	range = 2.0;

	std::cout << "Warrior default constructed." << std::endl;
}

Warrior::Warrior(int in_id, C_Point in_loc) : Person('W',in_id,in_loc){
	attack_strength = 2;
	range = 2.0;

	std::cout << "Warrior constructed." << std::endl;
}

Warrior::~Warrior(){
	std::cout << "Warrior destructed." << std::endl;
}

bool Warrior::start_attack(Person* in_target){
	if (is_alive()){	// Has to be alive to attack!
		if ((fabs(location.x-in_target->get_location().x) <= range) && (fabs(location.y-in_target->get_location().y) <= range)) {
			std::cout << display_code << get_id() << ": Attacking!" << std::endl;
			target = in_target;
			state = 'a';
			return true;
		}
		else {
			std::cout << display_code << get_id() << ": Target is out of range." << std::endl;
			return true;
		}
	}
	else {	// Won't attack if dead.
		std::cout << display_code << get_id() << " is dead." << std::endl;
		return false;
	}
}

bool Warrior::update(){
	switch (state){
		case 'x':{	// is dead
			return false;
		}
		case 's':{	// stopped
			return false;
		}
		case 'm':{	// Moving to a destination
			if (update_location()){
				state = 's';
				return true;
			}
			else
				return false;
		}
		case 'a':{	// Attacking
			if ((fabs(location.x-target->get_location().x) <= range) && (fabs(location.y-target->get_location().y) <= range)){
				if ((*target).is_alive()){
					std::cout << display_code << get_id() << ": Clang!" << std::endl;
					(*target).take_hit(attack_strength);
					return false;
				}
				else {
					std::cout << display_code << get_id() << ": I truimph!" << std::endl;
					state = 's';
					return true;
				}
			}
			else {
				std::cout << display_code << get_id() << ": Target is out of range." << std::endl;
				state = 's';	// Stop if not in range
				return true;
			}
		}
	}
}

void Warrior::show_status(){
	std::cout << "Warrior status: ";
	Person::show_status();
}

void Warrior::save(std::ofstream &file){

}

void Warrior::restore(std::ifstream &file, Model &model){
	
}