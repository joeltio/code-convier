#include "FiniteStateSystem.h"

namespace System {

void FiniteState::initialize(ECS::Manager* manager, Graphics* graphics, Input* input) {
	System::initialize(manager, graphics, input);

	// Create the GameState
	Entity::Game::create(manager);

	// Create the store
	this->store = new FSM::Store(manager, this->states);
	// Register the reducers
	for (FSM::Reducer* reducer : ENABLED_REDUCERS)
	{
		this->store->registerReducer(reducer);
	}

	// Initialize the store first
	for (Types::TypeId stateComponentTypeId : STATE_COMPONENT_TYPES)
	{
		// Retrieve the components for the current state type
		std::vector<Component::State>* componentsPtr =
			(std::vector<Component::State>*) this->manager->getComponents(stateComponentTypeId);

		for (Component::State& stateComp : *componentsPtr)
		{
			this->states.at(stateComp.state)->initialize(manager, graphics, input);
			this->states.at(stateComp.state)->enter(stateComp);
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
			FSM::Action action = this->states.at(stateComp.state)->update(frameTime, stateComp);
			action.dispatcherEntityId = stateComp.entityId;
			if (action.type != FSM::NO_ACTION) {
				this->store->dispatchAction(action);
			}
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
			FSM::Action action = this->states.at(stateComp.state)->render(stateComp);
			action.dispatcherEntityId = stateComp.entityId;
			if (action.type != FSM::NO_ACTION) {
				this->store->dispatchAction(action);
			}
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