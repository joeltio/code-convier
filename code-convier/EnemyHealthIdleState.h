#pragma once

#include "Action.h"
#include "State.h"
#include "HealthComponent.h"

class EnemyHealthIdleState : public FSM::State {
	FSM::Action update(float frametime, Component::State stateComponent);
};
