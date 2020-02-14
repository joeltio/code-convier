#pragma once
#include <string>
#include "Action.h"

const std::string IDLE_PLAYER_MOVEMENT = "IDLE";

struct IdlePlayerMovement : public FSM::Action {
	IdlePlayerMovement() : FSM::Action(IDLE_PLAYER_MOVEMENT) {}
};


