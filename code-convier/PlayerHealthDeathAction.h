#pragma once

#include <string>
#include "Action.h"

const std::string DEAD_PLAYER_HEALTH = "DEAD_HEALTH";

struct DeadPlayerHealth : public FSM::Action {
	DeadPlayerHealth() : FSM::Action(DEAD_PLAYER_HEALTH) {}
};


