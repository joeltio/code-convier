#pragma once

#include <iostream>
#include <fstream>
#include "Action.h"
#include "State.h"
#include "StateComponent.h"
#include "PlayerEntity.h"
#include "Entity.h"
#include "graphics.h"
#include "Manager.h"
#include "TextureComponent.h"
#include "SolidTileEntity.h"
#include "DecorativeTileEntity.h"
#include "EnemyEntity.h"
#include "HealthbarEntity.h"
#include "ResumeGameAction.h"

class GameCreateLevelState : public FSM::State {
	FSM::Action update(float frameTime, Component::State state);
	void enter(Component::State state);
	void exit(Component::State state);
};
