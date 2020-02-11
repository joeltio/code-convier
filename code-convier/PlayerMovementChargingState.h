#pragma once

#include "Action.h"
#include "State.h"
#include "PhysicsComponent.h"
#include "HealthComponent.h"

class PlayerMovementChargingState : public FSM::State {
	FSM::Action update(float frametime, Component::State stateComponent);
};
