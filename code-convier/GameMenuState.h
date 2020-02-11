#pragma once

#include "Action.h"
#include "State.h"
#include "StateComponent.h"
#include "MainMenuEntity.h"
#include "ButtonEntity.h"

class GameMenuState : public FSM::State {
	public:
		FSM::Action update(float frameTime, Component::State state);
		void enter(Component::State state);
		void exit(Component::State state);
};
