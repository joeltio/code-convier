#pragma once

#include <string>
#include "Action.h"

const std::string REPLENISHING_PLAYER_HEALTH = "REPLENISHING_HEALTH";

struct PlayerHealthReplenishing : public FSM::Action {
	PlayerHealthReplenishing() : FSM::Action(REPLENISHING_PLAYER_HEALTH) {}
};


