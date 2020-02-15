#pragma once

#include "Action.h"
#include "State.h"
#include "PlayerEntity.h"
#include "HealthComponent.h"
#include "CollidableComponent.h"
#include "EnergyOrbEntity.h"

class EnergyOrbHomingState : public FSM::State {
	FSM::Action update(float frametime, Component::State stateComponent);
};
