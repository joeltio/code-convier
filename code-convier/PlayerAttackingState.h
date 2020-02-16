#pragma once

#include "Action.h"
#include "State.h"
#include "PlayerEntity.h"
#include "EnemyEntity.h"
#include "TransformComponent.h"
#include "HurtBoxComponent.h"
#include "PlayerAttackIdleAction.h"

class PlayerAttackingState : public FSM::State {
	FSM::Action update(float frametime, Component::State stateComponent);
};
