#pragma once

#include "Action.h"
#include "State.h"
#include "StateComponent.h"

#include "PreparePlayerDeathAction.h"


class PlayerDeathState : public FSM::State {
	FSM::Action update(float frametime, Component::State stateComponent);
};
