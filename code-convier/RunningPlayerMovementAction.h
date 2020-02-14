#pragma once
#include <string>
#include "Action.h"

const std::string RUNNING_PLAYER_MOVEMENT = "RUNNING";

struct RunningPlayerMovement : public FSM::Action {
	RunningPlayerMovement() : FSM::Action(RUNNING_PLAYER_MOVEMENT) {}
};

