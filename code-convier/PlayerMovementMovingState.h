#pragma once

#include "Action.h"
#include "State.h"
#include "PhysicsComponent.h"
#include "JumpingComponent.h"
#include "HealthComponent.h"
#include "ChargeComponent.h"
#include "TransformComponent.h"
#include "ChargingPlayerMovementAction.h"
#include "MovingPlayerMovementAction.h"
#include "PlayerChargingIconEntity.h"
#include "PlayerRunningIconEntity.h"


class PlayerMovementMovingState : public FSM::State {
	FSM::Action update(float frametime, Component::State stateComponent);
};
