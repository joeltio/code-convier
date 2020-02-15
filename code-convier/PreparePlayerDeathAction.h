#pragma once

#include <string>
#include "Action.h"

const std::string PREPARE_PLAYER_DEATH_ACTION = "PREPARE_PLAYER_DEATH_ACTION";

struct PreparePlayerDeathAction : public FSM::Action {
	PreparePlayerDeathAction() : FSM::Action(PREPARE_PLAYER_DEATH_ACTION) {}
};