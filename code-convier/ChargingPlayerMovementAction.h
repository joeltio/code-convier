#pragma once
#include <string>
#include "Action.h"

const std::string CHARGING_PLAYER_MOVEMENT = "CHARGING";

struct ChargingPlayerMovement : public FSM::Action {
	ChargingPlayerMovement() : FSM::Action(CHARGING_PLAYER_MOVEMENT) {}
};

