#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H

#include "View.h"
#include "Model.h"

using namespace std;

//functions that respond to user input
void do_sail_command(Model& model);
void do_go_command(Model& model);
void do_run_command(Model& model);
void do_port_command(Model& model);
void do_hide_command(Model& model);
void do_anchor_command(Model& model);
void do_list_command(Model& model);
void do_dock_command(Model & model);

#endif
