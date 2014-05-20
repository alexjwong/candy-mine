#include "Game_Command.h"

bool do_move_command(Model &model){
	int objectId,paramx,paramy;
	if (!(std::cin >> objectId) || !(std::cin >> paramx) || !(std::cin >> paramy)){
		throw Invalid_Input("Was expecting ObjectId, X coordinate, Y coordinate");
		return false;
	}
	else if (model.get_Person_ptr(objectId) == NULL){
		std::cout << "Incorrect object id" << std::endl;
		return false;
	}
	else {	// Valid input
		if(model.get_Person_ptr(objectId)->start_moving(C_Point(paramx,paramy))){ // Check to see if not dead!
			return true;
		}
		else
			return false;
	}
}

bool do_mine_command(Model &model){
	int objectId,mine,tower;
	if (!(std::cin >> objectId) || !(std::cin >> mine) || !(std::cin >> tower)){
		throw Invalid_Input("Was expecting ObjectId, Mine, Tower");
		return false;
	}
	else if ((model.get_Person_ptr(objectId) == NULL) || (model.get_Candy_Mine_ptr(mine) == NULL) || (model.get_Tower_ptr(tower) == NULL)){
		throw Invalid_Input("Incorrect object id");
		return false;
	}
	else {	// Valid input
		if (model.get_Person_ptr(objectId)->start_mining(model.get_Candy_Mine_ptr(mine),model.get_Tower_ptr(tower))){ // Make sure not dead!
			return true;
		}
		else
			return false;
	}
}

bool do_stop_command(Model &model){
	int objectId;

	// Error checking 
	if ( !(std::cin >> objectId) ){
		throw Invalid_Input("Was expecting ObjectID");
		return false;
	}
	else if (model.get_Person_ptr(objectId) == NULL){
		throw Invalid_Input("Incorrect object id");
		return false;
	}
	else {	// Valid input
		if (model.get_Person_ptr(objectId)->stop()){	// Make sure not dead!
			return true;
		}
		else
			return false;
	}
}

bool do_attack_command(Model &model){
	int objectId,person;

	if ( !(std::cin >> objectId) || !(std::cin >> person) ){
		throw Invalid_Input("Was expecting ObjectId, Person");
		return false;
	}
	else if ((model.get_Person_ptr(objectId) == NULL) || (model.get_Person_ptr(person) == NULL)){
		throw Invalid_Input("Incorrect object id");
		return false;
	}
	else {	// Valid input
		if (model.get_Person_ptr(objectId)->start_attack(model.get_Person_ptr(person))){	// Make sure not dead!
			return true;
		}
		else
			return false;
	}
}

bool do_inspect_command(Model &model){
	int objectId;
	if ( !(std::cin >> objectId) ){
		throw Invalid_Input("Was expecting ObjectID");
		return false;
	}
	else if (model.get_Person_ptr(objectId) == NULL){
		throw Invalid_Input("Incorrect object id");
		return false;
	}
	else {	// Valid input
		if (model.get_Person_ptr(objectId)->start_inspecting(model)){	// Make sure not dead!
			return true;
		}
		else	// dead
			return false;
	}
}

bool do_new_command(Model &model){
	char type;
	int idnum,paramx,paramy;

	if ( !(std::cin >> type) || !(std::cin >> idnum) || !(std::cin >> paramx) || !(std::cin >> paramy)){
		throw Invalid_Input("Was expecting Type, ID number, X coordinate, Y coordinate");
		return false;
	}
	else {	// Valid input
		model.new_object(idnum,C_Point(paramx,paramy),type);	// Create new object of specified type
	}
}

void do_go_command(Model &model){
	std::cout << "Advancing one tick." << std::endl;
	model.update();
}

void do_run_command(Model &model){
	std::cout << "Advancing to next event." << std::endl;
	for (int i=0;i<5;i++){		// Advances 5 ticks...
		if (model.update()){	// or until a major event occurs.
			break;
		}
	}
}

bool do_save_command(Model &model){

}

bool do_restore_command(Model &model){
	
}