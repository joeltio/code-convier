#pragma once

#include <string>
#include "Action.h"

const std::string DESTROY_GAME_LEVEL_ACTION = "DESTROY_GAME_LEVEL_ACTION";

struct DestroyGameLevelAction : public FSM::Action {
	DestroyGameLevelAction() : FSM::Action(DESTROY_GAME_LEVEL_ACTION) {}
};
