#include "Inspector.h"
#include "Model.h"

Inspector::Inspector() : Person('I'){
	std::cout << "Inspector default constructed." << std::endl;
}

Inspector::Inspector(int in_id, C_Point in_loc) : Person('I',in_id,in_loc){
	std::cout << "Inspector constructed" << std::endl;
}

Inspector::~Inspector(){
	std::cout << "Inspector destructed." << std::endl;
}

bool Inspector::update(){
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
		case 'o':{	// Outbound to a mine
			if (update_location()){
				state = 'n';
				return true;
			}
			break;
		}
		case 'b':{	// Inbound to a mine
			if (update_location()){
				state = 'n';
				return true;
			}
			break;
		}
		case 'n':{	// Inspecting mine
			if (outbound_mine_ptrs.empty()){	// INBOUND
				// Compare amount of Candy
				std::cout << display_code << get_id() << ": Amount of Candy removed from this mine is " << 
					inbound_mine_ptrs.front()->get_Candy_amount() - outbound_amounts.front() << "." <<  std::endl;
				inbound_mine_ptrs.pop_front();
				outbound_amounts.pop_front();

				if (inbound_mine_ptrs.empty()){	// finished
					setup_destination(original_location);
					std::cout << display_code << get_id() << ": Inspection completed. Moving back to original location." << std::endl;
					state = 'm';
				}
				else {	// Setup next destination (still inbound)
					setup_destination(inbound_mine_ptrs.front()->get_location());
					state = 'b';
				}
			}
			else {	// OUTBOUND
				// Record amount of Candy in a mine
				outbound_amounts.push_front(outbound_mine_ptrs.front()->get_Candy_amount());
				std::cout << display_code << get_id() << ": This mine contains " << outbound_mine_ptrs.front()->get_Candy_amount() << " candy." << std::endl;

				inbound_mine_ptrs.push_front(outbound_mine_ptrs.front());		// Push last mine inspected to front of inbound mines
				outbound_mine_ptrs.pop_front();									// Delete first element of outbound to queue next mine

				if (outbound_mine_ptrs.empty()){	// Set up destination to reverse IF FINISHED OUTBOUND
					std::cout << display_code << get_id() << ": Starting back." << std::endl;
					
					inbound_mine_ptrs.pop_front();	// DON'T want to set location back to the one we were at, so delete it
					outbound_amounts.pop_front();	// Discard last mine visited as it won't change.

					setup_destination(inbound_mine_ptrs.front()->get_location());
					state = 'b';
				}
				else {	// Setup next destination (outbound)
					setup_destination(outbound_mine_ptrs.front()->get_location());
					state = 'o';
				}
			}
			break;
		}
		case 'x':{	// is dead
			return false;
		}
	}
	return false;
}

bool Inspector::start_inspecting(Model& model){
	if (is_alive()){	// Won't mine if dead!
		std::cout << display_code << get_id() << ": Starting inspection trip." << std::endl;
		original_location = get_location();
		outbound_mine_ptrs = model.get_Candy_Mine_list();				// Retrieve list of current Candy Mines and store it separately in Inspector
		setup_destination(outbound_mine_ptrs.front()->get_location());	// Set location to move to first mine
	
		state = 'o';
		return true;
	}
	else {	// Return false if dead.
		std::cout << display_code << get_id() << " is dead." << std::endl;
		return false;
	}
}

void Inspector::show_status(){
	std::cout << "Inspector status: ";
	Person::show_status();
}

void Inspector::save(std::ofstream &file){

}

void Inspector::restore(std::ifstream &file, Model &model){
	
}