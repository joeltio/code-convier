#pragma once

#include <string>
#include "Action.h"

const std::string CHASE_PLAYER_ACTION = "CHASE_PLAYER_ACTION";

struct ChasePlayerAction : public FSM::Action {
	ChasePlayerAction(): FSM::Action(CHASE_PLAYER_ACTION) {}
};
