#pragma once

#include "Action.h"
#include "State.h"
#include "PhysicsComponent.h"
#include "JumpingComponent.h"
#include "HealthComponent.h"
#include "ChargeComponent.h"
#include "TransformComponent.h"
#include "IdlePlayerMovementAction.h"
#include "ChargingPlayerMovementAction.h"
#include "WalkingPlayerMovementAction.h"

class PlayerMovementMovingState : public FSM::State {
	FSM::Action update(float frametime, Component::State stateComponent);
};
