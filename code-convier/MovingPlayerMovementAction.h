#pragma once
#include <string>
#include "Action.h"

const std::string MOVING_PLAYER_MOVEMENT = "MOVING";

struct MovingPlayerMovement : public FSM::Action {
	MovingPlayerMovement() : FSM::Action(MOVING_PLAYER_MOVEMENT) {}
};


