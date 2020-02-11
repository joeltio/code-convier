#pragma once

#include "Action.h"
#include "State.h"
#include "PhysicsComponent.h"
#include "JumpingComponent.h"

// player jumps with a constant V value

class PlayerMovementMovingState : public FSM::State {
	FSM::Action update(float frametime, Component::State stateComponent);
};
