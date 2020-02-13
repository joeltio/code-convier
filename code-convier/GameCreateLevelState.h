#pragma once

#include <fstream>
#include "Action.h"
#include "State.h"
#include "StateComponent.h"
#include "PlayerEntity.h"
#include "Entity.h"
#include "graphics.h"
#include "Manager.h"
#include "TextureComponent.h"

class GameCreateLevelState : public FSM::State {
	FSM::Action update(float frameTime, Component::State state);
};
