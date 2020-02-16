#include "PlayerDeathState.h"

FSM::Action PlayerDeathState::update(float frametime, Component::State stateComponent)
{
	// swap into death menu
	return PreparePlayerDeathAction();
}
