#pragma once

#include <string>
#include "Action.h"

const std::string PAUSE_GAME_ACTION = "PAUSE_GAME_ACTION";

struct PauseGameAction : public FSM::Action {
	std::string type = PAUSE_GAME_ACTION;
};
