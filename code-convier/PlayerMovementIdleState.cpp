#include "PlayerMovementIdleState.h"

FSM::Action PlayerMovementIdleState::update(float frameTime) {
	// check for inputs to move out of idle
	if (!input->anyKeyPressed()) {
		return FSM::NoAction();
	}
	return FSM::Action();
}
