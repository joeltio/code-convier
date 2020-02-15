#pragma once

#include "Reducer.h"
#include "State.h"

#include "GameEntity.h"
#include "GameStateComponent.h"

// Actions this reducer handles
#include "PrepareGameAction.h"
#include "PauseGameAction.h"
#include "PrepareMenuAction.h"
#include "QuitGameAction.h"
#include "ShowCreditsAction.h"
#include "ResumeGameAction.h"
#include "PrepareTemporaryAugmentationAction.h"
#include "PreparePlayerDeathAction.h"

// States that this reducer hanndles
#include "GameCreateLevelState.h"
#include "GameCreditsState.h"
#include "GameMenuState.h"
#include "GamePauseState.h"
#include "GameRunningState.h"
#include "GameAugmentationState.h"
#include "GamePlayerDeathState.h"

static std::string GAME_ACCEPTED_ACTIONS[] = {
	PREPARE_GAME_ACTION,
	PAUSE_GAME_ACTION,
	PREPARE_MENU_ACTION,
	QUIT_GAME_ACTION,
	SHOW_CREDITS_ACTION,
	RESUME_GAME_ACTION,
	PREPARE_TEMPORARY_AUGMENTATION_ACTION,
	PREPARE_PLAYER_DEATH_ACTION
};

class GameReducer : public FSM::Reducer {
	public:
		bool acceptsAction(FSM::Action &action);
		void reduce(
			ECS::Manager* manager,
			std::unordered_map<Types::TypeId, FSM::State*> states,
			FSM::Action action
		);
};
