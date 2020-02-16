#pragma once

#include "Action.h"
#include "Entity.h"
#include "State.h"
#include "StateComponent.h"

#include "PlayerDeathScreenEntity.h"

#include "QuitGameAction.h"

class GamePlayerDeathState : public FSM::State {
	FSM::Action update(float frameTime, Component::State state);
	void enter(Component::State state);
	void exit(Component::State state);
};
