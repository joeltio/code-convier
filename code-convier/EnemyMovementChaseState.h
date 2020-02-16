#pragma once

#include "Action.h"
#include "State.h"
#include "StateComponent.h"
#include "PhysicsComponent.h"
#include "LineOfSightComponent.h"
#include "EnemyAIComponent.h"
#include "AttackComponent.h"

#include "EnemyAttackAction.h"

class EnemyMovementChaseState : public FSM::State {
	FSM::Action update(float frameTime, Component::State state);
};
