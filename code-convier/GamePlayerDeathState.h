#pragma once

#include "Action.h"
#include "State.h"
#include "StateComponent.h"

class GamePlayerDeathState : FSM::State {
	FSM::Action update(float frameTime, Component::State state);
};
