#pragma once

#include <string>
#include "Action.h"

const std::string ORB_DETECT_PLAYER_ACTION = "ORB_DETECT_PLAYER_ACTION";

struct OrbDetectPlayerAction : public FSM::Action {
	OrbDetectPlayerAction() : FSM::Action(ORB_DETECT_PLAYER_ACTION) {}
};
