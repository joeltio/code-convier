#pragma once

#include "Action.h"
#include "State.h"
#include "PlayerEntity.h"
#include "TransformComponent.h"
#include "HurtBoxComponent.h"

class PlayerAttackingState : public FSM::State {
	FSM::Action update(float frametime, Component::State stateComponent);
};
