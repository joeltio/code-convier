#include "SystemRunner.h"

namespace ECS {

void SystemRunner::registerSystem(System* system) {
	this->systems.push_back(system);
}

void SystemRunner::initialize(Manager* manager, Graphics* graphics, Input* input) {
	this->graphics = graphics;
	for (ECS::System* systemPtr : this->getSystems()) {
		systemPtr->initialize(manager, graphics, input);
	}
}

void SystemRunner::update(float frameTime) {
	for (ECS::System* systemPtr : this->getSystems()) {
		systemPtr->update(frameTime);
	}
}

void SystemRunner::render() {
	this->graphics->beginScene();
	for (ECS::System* systemPtr : this->getSystems()) {
		systemPtr->render();
	}
	this->graphics->endScene();
}

void SystemRunner::releaseAll() {
	for (ECS::System* systemPtr : this->getSystems()) {
		systemPtr->releaseAll();
		SAFE_DELETE(systemPtr);
	}

	this->systems.clear();
}

void SystemRunner::resetAll() {
	for (ECS::System* systemPtr : this->getSystems()) {
		systemPtr->resetAll();
	}
}

}
