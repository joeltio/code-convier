#pragma once

#include "Action.h"
#include "State.h"
#include "EnemyEntity.h"
#include "HealthComponent.h"
#include "EnergyOrbEntity.h"

class EnemyDeathState : public FSM::State {
	FSM::Action update(float frametime, Component::State stateComponent);
};
