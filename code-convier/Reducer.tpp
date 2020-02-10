#ifndef REDUCER_TPP
#define REDUCER_TPP

#include "Reducer.h"

namespace FSM {

	template<typename NewStateType> void Reducer::changeState(
		std::unordered_map<Types::TypeId, State*>& states,
		Component::State& stateComponent
	) {
		// Exit the previous state
		states.at(stateComponent.state)->exit();

		// Update to the new state
		stateComponent.changeState<NewStateType>();

		// Enter new state
		Types::TypeId newStateTypeId = Types::toTypeId<NewStateType>();
		states.at(newStateTypeId)->enter();
	}

}

#endif
