#pragma once
#include <string>
#include "Action.h"

const std::string PLAYER_ATTACKING = "ATTACK";

struct PlayerAttacking : public FSM::Action {
	PlayerAttacking() : FSM::Action(PLAYER_ATTACKING) {}
};

