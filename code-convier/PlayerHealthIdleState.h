#pragma once

#include "Action.h"
#include "State.h"
#include "HealthComponent.h"

class PlayerHealthIdleState : public FSM::State {
	FSM::Action update(float frametime, Component::State stateComponent);
};
