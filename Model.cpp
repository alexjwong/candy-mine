#include "Model.h"

Model::Model(){
	time = 0;

	// Initialize objects
	Miner* m1 = new Miner(1,C_Point(5,1));
	Miner* m2 = new Miner(2,C_Point(10,1));
	Candy_Mine* c1 = new Candy_Mine(1,C_Point(1,20));
	Candy_Mine* c2 = new Candy_Mine(2,C_Point(10,20));
	Tower* t0 = new Tower;
	Warrior* w3 = new Warrior(3,C_Point(5,15));
	Warrior* w4 = new Warrior(4,C_Point(10,15));
	Inspector* i5 = new Inspector(5,C_Point(5,5));

	// Store the pointers in the object lists
	object_ptrs.push_back(m1);
	object_ptrs.push_back(m2);
	object_ptrs.push_back(c1);
	object_ptrs.push_back(c2);
	object_ptrs.push_back(t0);
	object_ptrs.push_back(w3);
	object_ptrs.push_back(w4);
	object_ptrs.push_back(i5);

	// All objects are alive at first
	active_ptrs.push_back(m1);
	active_ptrs.push_back(m2);
	active_ptrs.push_back(c1);
	active_ptrs.push_back(c2);
	active_ptrs.push_back(t0);
	active_ptrs.push_back(w3);
	active_ptrs.push_back(w4);
	active_ptrs.push_back(i5);

	person_ptrs.push_back(m1);
	person_ptrs.push_back(m2);
	person_ptrs.push_back(w3);
	person_ptrs.push_back(w4);
	person_ptrs.push_back(i5);

	mine_ptrs.push_back(c1);
	mine_ptrs.push_back(c2);

	tower_ptrs.push_back(t0);

	std::cout << "Model default constructed." << std::endl;
}

Model::~Model(){
	for (std::list<Game_Object*>::iterator i=object_ptrs.begin();i!=object_ptrs.end();i++){
		delete *i;	// Deallocate all objects
	}
	object_ptrs.clear();
	std::cout << "Model destructed." << std::endl;
}

Person* Model::get_Person_ptr(int id){
	for (std::list<Person*>::iterator i=person_ptrs.begin();i!=person_ptrs.end();i++){
		if ((*i)->get_id() == id){
			return *i;
		}
	}
	return NULL;
}

Candy_Mine* Model::get_Candy_Mine_ptr(int id){
	for (std::list<Candy_Mine*>::iterator i=mine_ptrs.begin();i!=mine_ptrs.end();i++){
		if ((*i)->get_id() == id){
			return *i;
		}
	}
	return NULL;
}

Tower* Model::get_Tower_ptr(int id){
	for (std::list<Tower*>::iterator i=tower_ptrs.begin();i!=tower_ptrs.end();i++){
		if ((*i)->get_id() == id){
			return *i;
		}
	}
	return NULL;
}

std::list<Candy_Mine*> Model::get_Candy_Mine_list(){
	return mine_ptrs;
}

void Model::new_object(int in_id, C_Point in_loc, char type){
	switch(type){
		case 'm':{	// Miner
			if (in_id <= person_ptrs.size()){
				throw Invalid_Input("That ID number already exists.");
			}
			else if (in_id > 9){
				throw Invalid_Input("No ID numbers greater than 9.");
			}
			else {
				Miner* object = new Miner(in_id,in_loc);
				object_ptrs.push_back(object);
				active_ptrs.push_back(object);
				person_ptrs.push_back(object);
			}
			break;
		}
		case 'w':{	// Warrior
			if (in_id <= person_ptrs.size()){
				throw Invalid_Input("That id number already exists.");
			}
			else if (in_id > 9){
				throw Invalid_Input("No ID numbers greater than 9.");
			}
			else {
				Warrior* object = new Warrior(in_id,in_loc);
				object_ptrs.push_back(object);
				active_ptrs.push_back(object);
				person_ptrs.push_back(object);
			}
			break;
		}
		case 'c':{
			if (in_id <= mine_ptrs.size()){
				throw Invalid_Input("That id number already exists.");
			}
			else if (in_id > 9){
				throw Invalid_Input("No ID numbers greater than 9.");
			}
			else {
				Candy_Mine* object = new Candy_Mine(in_id,in_loc);
				object_ptrs.push_back(object);
				active_ptrs.push_back(object);
				mine_ptrs.push_back(object);
			}
			break;
		}
		case 't':{
			if (in_id <= tower_ptrs.size()){
				throw Invalid_Input("That id number already exists.");
			}
			else if (in_id > 9){
				throw Invalid_Input("No ID numbers greater than 9.");
			}
			else {
				Tower* object = new Tower(in_id, in_loc);
				object_ptrs.push_back(object);
				active_ptrs.push_back(object);
				tower_ptrs.push_back(object);
			}
			break;
		}
	}
}

bool Model::update(){
	time++;
	bool updated = false;
	for (std::list<Game_Object*>::iterator i = active_ptrs.begin();i!=active_ptrs.end();i++){
		if ((*i)->update()){
			updated = true;
		}
		if (!(*i)->is_alive()){	// If object is dead, remove element from active ptrs
			active_ptrs.erase(i++);	// HAVE TO INCREMENT ITERATOR or else memory error
			std::cout << "Dead object removed." << std::endl;
		}
	}
	if (updated){
		return true;
	}
	else
		return false;
}

void Model::display(View &view){
	std::cout << "Time: " << time << std::endl;
	view.clear();
	for (std::list<Game_Object*>::iterator i = active_ptrs.begin();i!=active_ptrs.end();i++){
		view.plot(*i);
	}
	view.draw();
}

void Model::show_status(){
	for (std::list<Game_Object*>::iterator i = object_ptrs.begin();i!=object_ptrs.end();i++){
		(*i)->show_status();
	}
}