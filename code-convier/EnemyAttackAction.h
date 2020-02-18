#pragma once

#include <string>
#include "typeUtil.h"
#include "Entity.h"
#include "Action.h"

const std::string ENEMY_ATTACK_ACTION = "ENEMY_ATTACK_ACTION";

struct EnemyAttackAction : public FSM::Action {
	EnemyAttackAction() : FSM::Action(ENEMY_ATTACK_ACTION) {}
};

