#pragma once

#include <string>
#include "Action.h"

const std::string PAUSE_GAME_ACTION = "PAUSE_GAME_ACTION";

struct PauseGameAction : public FSM::Action {
	PauseGameAction(): FSM::Action(PAUSE_GAME_ACTION) {}
};
