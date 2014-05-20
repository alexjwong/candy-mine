#include <math.h>

#include "Person.h"

// Public member functions
Person::Person() : Game_Object(){	// Every person is a Game_Object
	speed = 5;
	health = 5;
	std::cout << "Person default constructed." << std::endl;
}

Person::Person(char in_code) : Game_Object(in_code){
	speed = 5;
	health = 5;
	std::cout << "Person constructed." << std::endl;
}

Person::Person(char in_code, int id_in, C_Point in_loc) : Game_Object(in_code,id_in,in_loc){
	speed = 5;
	health = 5;
	std::cout << "Person constructed." << std::endl;
}

Person::~Person(){
	std::cout << "Person destructed." << std::endl;
}

bool Person::start_moving(C_Point dest){
	if (is_alive()){	// Can't move if dead!
		setup_destination(dest);
		state = 'm';
		std::cout << "Moving " << get_id() << " to " << destination << std::endl;
		std::cout << display_code << get_id() << ": On my way." << std::endl;
		return true;
	}
	else {
		std::cout << display_code << get_id() << " is dead." << std::endl;
		return false;
	}
}

bool Person::stop(){
	if (is_alive()){	// Can't stop a zombie!
		state = 's';	// There was a bug that stopping a dead person would make them alive again by setting state to s
		std::cout << "Stopping " << get_id() << std::endl;
		std::cout << display_code << get_id() << ": All right." << std::endl;
		return true;
	}
	else {
		std::cout << display_code << get_id() << " is dead." << std::endl;
		return false;
	}
}

void Person::show_status(){
	Game_Object::show_status();
	switch (state){
		case 's':
			std::cout << "	Stopped." << std::endl;
			break;
		case 'm':
			std::cout << "	Moving at speed " << speed << " to " << destination << std::endl;
			std::cout << "	<X, Y> amounts on each step are " << delta << "." << std::endl;
			break;
		case 'o':
			std::cout << "	Outbound to a mine." << std::endl;
			break;
		case 'b':
			std::cout << "	Inbound to a mine." << std::endl;
			break;
		case 'g':
			std::cout << "	Getting candy from mine." << std::endl;
			break;
		case 'i':
			std::cout << "	Not yet upgraded" << std::endl;
			break;
		case 'd':
			std::cout << "	Depositing candy." << std::endl;
			break;
		case 'n':
			std::cout << "	Inspecting mine." << std::endl;
			break;
		case 'x':
			std::cout << "	is dead." << std::endl;
			break;
	}
	if (state != 'x'){	// If not dead, print amount of health
		std::cout << "	Health: " << health << std::endl;
	}
}

bool Person::is_alive(){
	if (state == 'x'){	// Dead
		return false;
	}
	else
		return true;	// Alive
}

void Person::take_hit(int attack_strength){
	health = health - attack_strength;
	if (health <= 0){
		health = 0;	// Make sure health can't be negative
		std::cout << display_code << get_id() << ": Arrggh!" << std::endl;
		state = 'x';
	}
	else
		std::cout << display_code << get_id() << ": Ouch!" << std::endl;
}

bool Person::start_attack(Person* target){	// Only warriors can attack.
	std::cout << display_code << get_id() << ": I can't attack." << std::endl;
	return false;
}

bool Person::start_mining(Candy_Mine* inputMine, Tower* inputHome){	// Only miners can mine
	std::cout << display_code << get_id() << ": Sorry, I can't work a mine." << std::endl;
	return false;
}

bool Person::start_inspecting(Model &model){
	std::cout << display_code << get_id() << ": Sorry, I can't inspect." << std::endl;
	return false;
}


// Protected member functions
bool Person::update_location(){
	// Check to see if the miner is within a step of the destination
	if ((fabs(destination.x-location.x) <= fabs(delta.x)) && (fabs(destination.y-location.y) <= fabs(delta.y))){
		location = destination;
		std::cout << display_code << get_id() << ": I'm there!" << std::endl;
		return true;
	}
	else {
		// Add the delta to the current location
		location.x += delta.x;
		location.y += delta.y;
		std::cout << display_code << get_id() << ": step..." << std::endl;
		return false;
	}
}

void Person::setup_destination(C_Point dest){	// Setup speed and delta
	if ((get_location().x == dest.x) && (get_location().y == dest.y)){
		// Fixes error that occured when setting up a destination to the same point one was on.
		std::cout << display_code << get_id() << ": Already at the destination!" << std::endl;
	}
	else {
		destination = dest;
		delta = C_Vector(destination.x-location.x,destination.y-location.y) * (speed / C_distance(destination, location));
	}
}

void Person::save(std::ofstream &file){

}

void Person::restore(std::ifstream &file, Model &model){
	
}