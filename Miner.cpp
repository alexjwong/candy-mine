#include <iostream>
#include <math.h>

#include "Miner.h"

// ***Constructors***

Miner::Miner() : Person('M'){
	amount = 0;
	mine = NULL;
	home = NULL;

	std::cout << "Miner default constructed." << std::endl;
}

Miner::Miner(int in_id, C_Point in_loc) : Person('M',in_id,in_loc){
	amount = 0;
	mine = NULL;
	home = NULL;

	std::cout << "Miner constructed." << std::endl;
}

Miner::~Miner(){
	std::cout << "Miner destructed." << std::endl;
}


// ***Public member functions***

bool Miner::update(){
	switch (state){
		case 's':	// Stopped
			break;
		case 'm':{	// Moving to a destination
			if (update_location()){
				state = 's';
				return true;
			}
			break;
		}
		case 'o':{	// Outbound mining
			if (update_location()){
				state = 'g';
				return true;
			}
			break;
		}
		case 'g':{	// Getting candy
			amount = (*mine).dig_candy();
			std::cout << display_code << get_id() << ": Got " << amount << " candy." << std::endl;
			setup_destination((*home).get_location());
			state = 'i';
			return true;
			break;
		}
		case 'i':{	// Inbound mining
			if (update_location()){
				state = 'd';
			}
			break;
		}
		case 'd':{	// Depositing candy
			std::cout << display_code << get_id() << ": Deposit " << amount << " of candy" << std::endl;
			(*home).deposit_candy(amount);
			amount = 0;
			if ((*mine).is_empty()){
				state = 's';
				std::cout << display_code << get_id() << ": More work?" << std::endl;
				return true;
			}
			else {
				setup_destination((*mine).get_location());
				state = 'o';
				std::cout << display_code << get_id() << ": Going back for more." << std::endl;
			}
			break;
		}
		case 'x':{	// is dead
			return false;
		}
	}
	return false;
}

bool Miner::start_mining(Candy_Mine* inputMine, Tower* inputHome){
	if (is_alive()){	// Won't mine if dead!
		mine = inputMine;
		home = inputHome;
		setup_destination((*mine).get_location());	// Outbound to a mine
		state = 'o';
		std::cout << "Miner " << get_id() << " mining at Candy_Mine " 
			<< (*mine).get_id() << " and depositing at Tower " << (*home).get_id() << std::endl;
		std::cout << display_code << get_id() << ": Yes, my lord." << std::endl;
		return true;
	}
	else {	// Return false if dead.
		std::cout << display_code << get_id() << " is dead." << std::endl;
		return false;
	}
	
}

void Miner::show_status(){
	std::cout << "Miner status: ";
	Person::show_status();
}

void Miner::save(std::ofstream &file){

}

void Miner::restore(std::ifstream &file, Model &model){
	
}