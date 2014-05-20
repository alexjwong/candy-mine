#include <iostream>

#include "Candy_Mine.h"
#include "Miner.h"
#include "Tower.h"
#include "Game_Object.h"
#include "Person.h"
#include "View.h"
#include "Model.h"
#include "Input_Handling.h"

// Function prototypes for Game_Command
bool do_move_command(Model &model);
bool do_mine_command(Model &model);
bool do_stop_command(Model &model);
bool do_attack_command(Model &model);
bool do_inspect_command(Model &model);
bool do_new_command(Model &model);
void do_go_command(Model &model);
void do_run_command(Model &model);
bool do_save_command(Model &model);
bool do_restore_command(Model &model);

