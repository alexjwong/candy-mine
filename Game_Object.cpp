#include "Game_Object.h"

// Public Member functions
Game_Object::Game_Object(){
	display_code = ' ';
	state = 's';
	id_num = 0;
	location = C_Point();
	std::cout << "Game_Object default constructed." << std::endl;
}

Game_Object::Game_Object(char in_code){
	display_code = in_code;
	state = 's';
	id_num = 0;
	location = C_Point();
	std::cout << "Game_Object constructed." << std::endl;
}

Game_Object::Game_Object(char in_code, int in_id, C_Point in_loc){
	display_code = in_code;
	state = 's';
	id_num = in_id;
	location = in_loc;
	std::cout << "Game_Object constructed." << std::endl;

}

Game_Object::~Game_Object(){
	std::cout << "Game_Object destructed." << std::endl;
}

C_Point Game_Object::get_location(){
	return location;
}

int Game_Object::get_id(){
	return id_num;
}

void Game_Object::show_status(){
	std::cout << display_code << id_num << " at " << location << std::endl;
}

void Game_Object::drawself(char * ptr){
	ptr[0] = display_code;
	ptr[1] = '0' + id_num;
}

bool Game_Object::update(){
	return true;
}

bool Game_Object::is_alive(){
	return true;
}

void Game_Object::save(std::ofstream &file){

}

void Game_Object::restore(std::ifstream &file, Model &model){

}