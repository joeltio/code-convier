#pragma once

#include "Action.h"
#include "State.h"
#include "StateComponent.h"
#include "TransformComponent.h"
#include "TextureComponent.h"
#include "AugmentationComponent.h"
#include "TextComponent.h"
#include "QuitGameAction.h"
#include "ShowCreditsAction.h"
#include "PrepareGameAction.h"
#include "PauseGameAction.h"
#include "ResumeGameAction.h"
#include "PrepareMenuAction.h"


class NotClickedState : public FSM::State {
	FSM::Action update(float frameTime, Component::State state);
};