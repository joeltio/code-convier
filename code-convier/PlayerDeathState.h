#pragma once

#include "Action.h"
#include "State.h"

#include "PlayerEntity.h"

#include "PreparePlayerDeathAction.h"

class PlayerDeathState : public FSM::State {
	FSM::Action update(float frametime);
};
