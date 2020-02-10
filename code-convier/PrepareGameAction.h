#pragma once

#include <string>
#include "Action.h"

const std::string PREPARE_GAME_ACTION = "PREPARE_GAME_ACTION";

struct PrepareGameAction : public FSM::Action {
	std::string type = PREPARE_GAME_ACTION;
};
