#pragma once

#include "Action.h"
#include "State.h"
#include "StateComponent.h"

#include "GameEntity.h"
#include "PlayerEntity.h"
#include "TransformComponent.h"
#include "PauseGameAction.h"
#include "HealthbarEntity.h"

class GameRunningState : public FSM::State {
	FSM::Action update(float frameTime, Component::State state);
	void exit(Component::State state);
};
