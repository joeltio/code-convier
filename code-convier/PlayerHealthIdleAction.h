#pragma once

#include <string>
#include "Action.h"

const std::string IDLE_PLAYER_HEALTH = "IDLE_HEALTH";

struct IdlePlayerHealth : public FSM::Action {
	IdlePlayerHealth() : FSM::Action(IDLE_PLAYER_HEALTH) {}
};


