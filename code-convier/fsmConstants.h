#pragma once

#include "Reducer.h"
#include "typeUtil.h"

// Components
#include "GameStateComponent.h"
#include "ClickStateComponent.h"
#include "PlayerMovementStateComponent.h"

// States
#include "GameCreateLevelState.h"
#include "GameCreditsState.h"
#include "GameMenuState.h"
#include "GamePauseState.h"
#include "GamePlayerDeathState.h"
#include "GameRunningState.h"

#include "ClickingState.h"
#include "NotClickedState.h"

#include "PlayerMovementIdleState.h"
#include "PlayerMovementMovingState.h"
#include "PlayerMovementChargingState.h"

// Reducers
#include "GameReducer.h"
#include "PlayerMovementReducer.h"

// List of all the components which store states for FSMs
const Types::TypeId STATE_COMPONENT_TYPES[] = {
	Types::toTypeId<Component::GameState>(),
	Types::toTypeId<Component::ClickState>(),
	Types::toTypeId<Component::PlayerMovementState>()
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
	{Types::toTypeId<NotClickedState>(), new NotClickedState()},
	{Types::toTypeId<PlayerMovementIdleState>(), new PlayerMovementIdleState()},
	{Types::toTypeId<PlayerMovementMovingState>(), new PlayerMovementMovingState()},
	{Types::toTypeId<PlayerMovementChargingState>(), new PlayerMovementChargingState()}
});


// Lists all reducers
static FSM::Reducer* ENABLED_REDUCERS[] = {
	new GameReducer(),
	new PlayerMovementReducer()
};
