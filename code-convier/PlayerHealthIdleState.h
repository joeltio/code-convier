#pragma once

#include "Action.h"
#include "State.h"
#include "StateComponent.h"

#include "HealthComponent.h"
#include "PlayerEntity.h"

#include "PlayerHealthDeathAction.h"
#include "PlayerHealthReplenishingAction.h"

class PlayerHealthIdleState : public FSM::State {
	FSM::Action update(float frametime, Component::State stateComponent);
};
