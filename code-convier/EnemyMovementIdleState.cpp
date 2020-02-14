#include "EnemyMovementIdleState.h"

FSM::Action EnemyMovementIdleState::update(float frameTime, Component::State state) {
	// Wait for game to unpause and change state
	return FSM::NoAction();
}
