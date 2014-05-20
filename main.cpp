#include <iostream>

#include "C_Point.h"
#include "C_Vector.h"
#include "Game_Object.h"
#include "Candy_Mine.h"
#include "Tower.h"
#include "Person.h"
#include "Miner.h"
#include "Warrior.h"
#include "Inspector.h"
#include "View.h"
#include "Model.h"
#include "Game_Command.h"
#include "Input_Handling.h"


int main(){

	// Local variables
	bool gameOver = false;
	bool correctInput = true;
	char command;

	// Declare model (contains all objects)
	Model game;

	// Declare view object
	View board;

	// Main game loop
	while (gameOver == false){		
		if (correctInput == true){	// Only print the board if a correct command was entered
			game.display(board);	// Print board
			correctInput = false;	// reset variable
		}

		std::cout << "Enter command: " << std::endl;
		std::cin >> command;	// Input
		
		try {
			switch (command){
				case 'm':{	// Move to location
					if (do_move_command(game)){
						correctInput = true;
					}
					break;
				}
				case 'w':{	// Work a mine
					if (do_mine_command(game)){
						correctInput = true;
					}
					break;
				}
				case 's':{	// Stop miner
					if (do_stop_command(game)){
						correctInput = true;
					}
					break;
				}
				case 'g':{	// Advance one time step
					do_go_command(game);
					correctInput = true;
					break;
				}
				case 'r':{	// Advance 5 time steps or until a major event occurs
					do_run_command(game);
					correctInput = true;
					break;
				}
				case 'a':{	// Attack another person
					if (do_attack_command(game)){
						correctInput = true;
					}
					break;
				}
				case 'i':{	// Command an Inspector to inspect Candy Mines
					if (do_inspect_command(game)){
						correctInput = true;
					}
					break;
				}
				case 'l':{	// List the status of all objects
					game.show_status();
					correctInput = true;
					break;
				}
				case 'n':{	// Create a new object
					if (do_new_command(game)){
						correctInput = true;
					}
					break;
				}
				case 'q':{	// Quit
					std::cout << "Terminating program." << std::endl;
					gameOver = true;
					return 0;
					break;
				}
				case 'S':{	// Save a game
					if (do_save_command(game)){
						correctInput = true;
					}
					break;
				}
				case 'R':{	// Restore a game
					if (do_restore_command(game)){
						correctInput = true;
					}
					break;
				}
				default:{
					correctInput = false;
					throw Invalid_Input("Unrecognized command");
					break;
				}
			}
		}
		catch (Invalid_Input& except){
			std::cout << "Invalid input - " << except.msg_ptr << std::endl;
			std::cin.clear();				// Clear rest of line so that any other commands are ignored
			std::cin.ignore(10000, '\n');
		}
	}
	return 0;
}