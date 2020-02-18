#pragma once

#include "Reducer.h"
#include "typeUtil.h"

// Components
#include "GameStateComponent.h"
#include "ClickStateComponent.h"
#include "PlayerMovementStateComponent.h"
#include "PlayerAttackStateComponent.h"
#include "PlayerHealthStateComponent.h"
#include "EnergyOrbStateComponent.h"
#include "EnemyMovementStateComponent.h"

// States
#include "GameCreateLevelState.h"
#include "GameCreditsState.h"
#include "GameMenuState.h"
#include "GamePauseState.h"
#include "GamePlayerDeathState.h"
#include "GameRunningState.h"
#include "GameDestroyLevelState.h"

#include "ClickingState.h"
#include "NotClickedState.h"

#include "PlayerMovementMovingState.h"
#include "PlayerMovementChargingState.h"

#include "PlayerAttackIdleState.h"
#include "PlayerAttackingState.h"

#include "EnergyOrbHomingState.h"
#include "EnergyOrbIdleState.h"

#include "PlayerHealthIdleState.h"
#include "PlayerHealthReplenishingState.h"
#include "PlayerDeathState.h"

#include "EnemyMovementIdleState.h"
#include "EnemyMovementChaseState.h"
#include "SkeletonAttackState.h"

// Reducers
#include "GameReducer.h"
#include "PlayerMovementReducer.h"
#include "PlayerAttackReducer.h"
#include "PlayerHealthReducer.h"
#include "EnergyOrbReducer.h"
#include "EnemyMovementReducer.h"

// List of all the components which store states for FSMs
const Types::TypeId STATE_COMPONENT_TYPES[] = {
	Types::toTypeId<Component::GameState>(),
	Types::toTypeId<Component::ClickState>(),
	Types::toTypeId<Component::PlayerMovementState>(),
	Types::toTypeId<Component::EnergyOrbState>(),
	Types::toTypeId<Component::PlayerMovementState>(),
	Types::toTypeId<Component::PlayerAttackState>(),
	Types::toTypeId<Component::PlayerHealthState>(),
	Types::toTypeId<Component::EnemyMovementState>()
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
	{Types::toTypeId<PlayerMovementMovingState>(), new PlayerMovementMovingState()},
	{Types::toTypeId<PlayerMovementChargingState>(), new PlayerMovementChargingState()},
	{Types::toTypeId<EnergyOrbHomingState>(), new EnergyOrbHomingState()},
	{Types::toTypeId<EnergyOrbIdleState>(), new EnergyOrbIdleState()},
	{Types::toTypeId<PlayerAttackIdleState>(), new PlayerAttackIdleState()},
	{Types::toTypeId<PlayerAttackingState>(), new PlayerAttackingState()},
	{Types::toTypeId<PlayerHealthIdleState>(), new PlayerHealthIdleState()},
	{Types::toTypeId<PlayerHealthReplenishingState>(), new PlayerHealthReplenishingState()},
	{Types::toTypeId<PlayerDeathState>(), new PlayerDeathState()},
	{Types::toTypeId<GameDestroyLevelState>(), new GameDestroyLevelState()},
	{Types::toTypeId<EnemyMovementIdleState>(), new EnemyMovementIdleState()},
	{Types::toTypeId<EnemyMovementChaseState>(), new EnemyMovementChaseState()},
	{Types::toTypeId<SkeletonAttackState>(), new SkeletonAttackState()}
});


// Lists all reducers
static FSM::Reducer* ENABLED_REDUCERS[] = {
	new GameReducer(),
	new PlayerMovementReducer(),
	new PlayerAttackReducer(),
	new PlayerMovementReducer(),
	new PlayerHealthReducer(),
	new EnergyOrbReducer(),
	new EnemyMovementReducer()
};
