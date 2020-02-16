#pragma once

#include "Action.h"
#include "State.h"
#include "PlayerEntity.h"
#include "AttackComponent.h"
#include "PlayerAttackingAction.h"

class PlayerAttackIdleState : public FSM::State {
	FSM::Action update(float frametime, Component::State stateComponent);
};
