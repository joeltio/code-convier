#include "State.h"

namespace FSM {

void State::initialize(ECS::Manager* manager, Graphics* graphics, Input* input) {
	this->manager = manager;
	this->graphics = graphics;
	this->input = input;
}

}