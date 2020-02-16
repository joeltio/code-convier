#include "PlayerMovementIdleState.h"

FSM::Action PlayerMovementIdleState::update(float frameTime, Component::State stateComponent) {
	// paused state 
	return FSM::NoAction();
}