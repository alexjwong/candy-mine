#include "Candy_Mine.h"

// Constructors

Candy_Mine::Candy_Mine() : Game_Object('C'){

	state = 'f';
	amount = 100;

	std::cout << "Candy_Mine default constructed." << std::endl;
}

Candy_Mine::Candy_Mine(int in_id, C_Point in_loc) : Game_Object('C',in_id,in_loc){

	state = 'f';
	amount = 100;

	std::cout << "Candy_Mine constructed." << std::endl;
}

Candy_Mine::~Candy_Mine(){
	std::cout << "Candy_Mine destructed." << std::endl;
}


bool Candy_Mine::is_empty(){
	if (amount == 0){
		return true;
	}
	else
		return false;
}

double Candy_Mine::dig_candy(double amount_to_dig){
	int currentAmount;

	if (amount >= amount_to_dig){
		amount = amount - amount_to_dig;
		return amount_to_dig;
	}
	else {
		currentAmount = amount;
		amount = 0;
		return currentAmount;
	}
}

bool Candy_Mine::update(){
	if (amount == 0 && state == 'f'){
		state = 'e';
		display_code = 'c';
		std::cout << "Candy_Mine (" << get_id() << ") has been depleted." << std::endl;
		return true;
	}
	else
		return false;
}

void Candy_Mine::show_status(){
	std::cout << "Candy_Mine status: ";
	Game_Object::show_status();
	std::cout << "	Contains " << amount << "." << std::endl;
}

double Candy_Mine::get_Candy_amount(){
	return amount;
}

void Candy_Mine::save(std::ofstream &file){

}

void Candy_Mine::restore(std::ifstream &file, Model &model){

}