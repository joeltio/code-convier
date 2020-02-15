#pragma once

#include "Entity.h"
#include "Action.h"
#include "State.h"
#include "PlayerEntity.h"
#include "EnemyEntity.h"
#include "StateComponent.h"
#include "AttackComponent.h"
#include "TextureComponent.h"
#include "HurtBoxComponent.h"
#include "ChasePlayerAction.h"

class SkeletonAttackState : public FSM::State {
	void enter(Component::State state);
	FSM::Action update(float frameTime, Component::State state);
	void exit(Component::State state);
};
