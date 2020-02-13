#pragma once

#include "Reducer.h"
#include "typeUtil.h"

// Components
#include "GameStateComponent.h"
#include "ClickStateComponent.h"

// States
#include "GameCreateLevelState.h"
#include "GameCreditsState.h"
#include "GameMenuState.h"
#include "GamePauseState.h"
#include "GamePlayerDeathState.h"
#include "GameRunningState.h"

#include "ClickingState.h"
#include "NotClickedState.h"

// Reducers
#include "GameReducer.h"


// List of all the components which store states for FSMs
const Types::TypeId STATE_COMPONENT_TYPES[] = {
	Types::toTypeId<Component::GameState>(),
	Types::toTypeId<Component::ClickState>()
};


// Maps all state types to their static object instance
const std::unordered_map<Types::TypeId, FSM::State*> TYPE_STATE_MAP({
	{Types::toTypeId<GameMenuState>(), new GameMenuState()},
	{Types::toTypeId<GameCreateLevelState>(), new GameCreateLevelState()},
	{Types::toTypeId<GameCreditsState>(), new GameCreditsState()},
	{Types::toTypeId<GamePauseState>(), new GamePauseState()},
	{Types::toTypeId<GamePlayerDeathState>(), new GamePlayerDeathState()},
	{Types::toTypeId<GameRunningState>(), new GameRunningState()},
	{Types::toTypeId<ClickingState>(), new ClickingState()},
	{Types::toTypeId<NotClickedState>(), new NotClickedState()}
});


// Lists all reducers
static FSM::Reducer* ENABLED_REDUCERS[] = {
	new GameReducer()
};
