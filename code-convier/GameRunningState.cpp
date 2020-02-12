#include "GameRunningState.h"

FSM::Action GameRunningState::update(float frameTime, Component::State state) {
	if (this->input->isKeyDown(VK_ESCAPE)) {
		return PauseGameAction();
	}
	return FSM::NoAction();
}