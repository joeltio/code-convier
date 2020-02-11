#pragma once

#include <string>
#include "Action.h"

const std::string QUIT_GAME_ACTION = "QUIT_GAME_ACTION";

struct QuitGameAction : public FSM::Action {
	QuitGameAction(): FSM::Action(QUIT_GAME_ACTION) {}
};