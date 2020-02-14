#pragma once
#include <string>
#include "Action.h"

const std::string WALKING_PLAYER_MOVEMENT = "WALKING";

struct WalkingPlayerMovement : public FSM::Action {
	WalkingPlayerMovement() : FSM::Action(WALKING_PLAYER_MOVEMENT) {}
};


