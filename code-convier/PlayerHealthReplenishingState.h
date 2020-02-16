#pragma once

#include "Action.h"
#include "State.h"
#include "PlayerEntity.h"
#include "PlayerHealthIdleAction.h"

class PlayerHealthReplenishingState : public FSM::State {
	FSM::Action update(float frametime, Component::State stateComponent);
};
