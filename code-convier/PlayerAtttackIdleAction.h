#pragma once
#include <string>
#include "Action.h"

const std::string PLAYER_ATTACK_IDLE = "ATTACK_IDLE";

struct PlayerAttackingIdle : public FSM::Action {
	PlayerAttackingIdle() : FSM::Action(PLAYER_ATTACK_IDLE) {}
};
