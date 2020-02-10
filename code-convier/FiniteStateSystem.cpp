#include "FiniteStateSystem.h"

namespace System {

void FiniteState::initialize(ECS::Manager* manager, Graphics* graphics, Input* input) {
	System::initialize(manager, graphics, input);

	// Create the GameState
	Entity::Game::create(manager);

	// Create the store
	this->store = new FSM::Store(manager);
	// Register the reducers

	// Initialize the store first
	for (Types::TypeId stateComponentTypeId : STATE_COMPONENT_TYPES)
	{
		// Retrieve the components for the current state type
		std::vector<Component::State>* componentsPtr =
			(std::vector<Component::State>*) this->manager->getComponents(stateComponentTypeId);

		for (Component::State& stateComp : *componentsPtr)
		{
			this->states.at(stateComp.state)->initialize(manager, graphics, input, this->store);
		}
	}
}

void FiniteState::update(float frameTime) {
	for (Types::TypeId stateComponentTypeId : STATE_COMPONENT_TYPES)
	{
		// Retrieve the components for the current state type
		std::vector<Component::State>* componentsPtr =
			(std::vector<Component::State>*) this->manager->getComponents(stateComponentTypeId);

		for (Component::State& stateComp : *componentsPtr)
		{
			this->states.at(stateComp.state)->update(frameTime);
		}
	}
}

void FiniteState::render() {
	for (Types::TypeId stateComponentTypeId : STATE_COMPONENT_TYPES)
	{
		// Retrieve the components for the current state type
		std::vector<Component::State>* componentsPtr =
			(std::vector<Component::State>*) this->manager->getComponents(stateComponentTypeId);

		for (Component::State& stateComp : *componentsPtr)
		{
			this->states.at(stateComp.state)->render();
		}
	}
}

void FiniteState::releaseAll() {
	// Delete the states in the states map
	for (std::pair<Types::TypeId, FSM::State*> mapPair : this->states)
	{
		SAFE_DELETE(this->states.at(mapPair.first));
	}

	// Delete the store
	SAFE_DELETE(this->store);

	// Call super
	System::releaseAll();
}

}