#include "State.h"

namespace FSM {

void State::initialize(ECS::Manager* manager, Graphics* graphics, Input* input, Store* store) {
	this->manager = manager;
	this->graphics = graphics;
	this->input = input;
	this->store = store;
}

}