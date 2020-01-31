#include "System.h"

namespace ECS {

System::System() {}

System::~System() {
	this->manager = NULL;
	this->graphics = NULL;
	this->input = NULL;
}

void System::initialize(Manager* manager, Graphics* graphics, Input* input) {
	this->manager = manager;
	this->graphics = graphics;
	this->input = input;
}

}