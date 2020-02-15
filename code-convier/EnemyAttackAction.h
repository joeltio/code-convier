#pragma once

#include <string>
#include "typeUtil.h"
#include "Entity.h"
#include "Action.h"

const std::string ENEMY_ATTACK_ACTION = "ENEMY_ATTACK_ACTION";

struct EnemyAttackAction : public FSM::Action {
	Types::TypeId enemyType = Types::NothingTypeId;

	EnemyAttackAction(Types::TypeId enemyType) : FSM::Action(ENEMY_ATTACK_ACTION) {
		this->enemyType = enemyType;
	}
};

