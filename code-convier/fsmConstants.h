#pragma once

#include "typeUtil.h"

// Components
#include "GameStateComponent.h"

// States
#include "GameMenuState.h"

// List of all the components which store states for FSMs
const Types::TypeId STATE_COMPONENT_TYPES[] = {
	Types::toTypeId<Component::GameState>()
};


// Maps all state types to their static object instance
const std::unordered_map<Types::TypeId, FSM::State*> TYPE_STATE_MAP({
	{Types::toTypeId<GameMenuState>(), new GameMenuState()}
});
