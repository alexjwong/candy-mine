#include "Tower.h"

Tower::Tower() : Game_Object('t') {	// Towers are Game_Objects
	state = 'o';
	amount = 0;

	std::cout << "Tower default constructed." << std::endl;
}

Tower::Tower(int in_id, C_Point in_loc) : Game_Object('t',in_id,in_loc){
	state = 'o';
	amount = 0;

	std::cout << "Tower constructed." << std::endl;
}

Tower::~Tower(){
	std::cout << "Tower destructed." << std::endl;
}

void Tower::deposit_candy(double deposit_amount){
	amount = amount + deposit_amount;
}

bool Tower::update(){
	if (amount >= 50 && state == 'o'){	// Check to see if tower should be upgraded
		state = 'u';
		display_code = 'T';

		std::cout << "Tower (" << get_id() << ") has been upgraded." << std::endl;
		return true;
	}
	else
		return false;
}

void Tower::show_status(){
	std::cout << "Tower status: ";
	Game_Object::show_status();
	std::cout << "	Contains " << amount << "." << std::endl;
	if (state == 'u'){
		std::cout << "	Upgraded" << std::endl;
	}
	else
		std::cout << "	Not yet upgraded" << std::endl;
}

void Tower::save(std::ofstream &file){

}

void Tower::restore(std::ifstream &file, Model &model){
	
}