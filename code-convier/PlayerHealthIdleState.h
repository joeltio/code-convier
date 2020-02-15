#pragma once

#include "Action.h"
#include "State.h"
#include "StateComponent.h"

#include "HealthComponent.h"
#include "PlayerEntity.h"

#include "PreparePlayerDeathAction.h"

class PlayerHealthIdleState : public FSM::State {
	FSM::Action update(float frametime, Component::State stateComponent);
};
