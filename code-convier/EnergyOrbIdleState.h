#pragma once

#include "Action.h"
#include "State.h"
#include "PlayerEntity.h"
#include "CollidableComponent.h"
#include "EnergyOrbEntity.h"
#include "OrbDetectPlayerAction.h";

class EnergyOrbIdleState : public FSM::State {
	FSM::Action update(float frametime, Component::State stateComponent);
};
