#pragma once

#include "State.h"
#include "SolidTileEntity.h"
#include "DecorativeTileEntity.h"
#include "PlayerEntity.h"
#include "EnemyEntity.h"
#include "PlayerRunningIconEntity.h"
#include "PlayerChargingIconEntity.h"
#include "HealthbarEntity.h"
#include "GameStateComponent.h"

class GameDestroyLevelState : public FSM::State {
	FSM::Action update(float frameTime, Component::State state);
	void enter(Component::State state);
	void exit(Component::State state);
};