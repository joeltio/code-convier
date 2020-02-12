#pragma once

#include "Action.h"
#include "Entity.h"
#include "State.h"
#include "StateComponent.h"

#include "CreditsEntity.h"

#include "TextureComponent.h"
#include "PrepareMenuAction.h"


class GameCreditsState : public FSM::State {
	FSM::Action update(float frameTime, Component::State state);
	void enter(Component::State state);
	void exit(Component::State state);
};
