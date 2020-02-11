#pragma once

#include <string>
#include "Action.h"

const std::string PREPARE_MENU_ACTION = "PREPARE_MENU_ACTION";

struct PrepareMenuAction : public FSM::Action {
	std::string type = PREPARE_MENU_ACTION;
};
