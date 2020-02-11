#pragma once

#include <string>
#include "Action.h"

const std::string RESUME_GAME_ACTION = "RESUME_GAME_ACTION";

struct ResumeGameAction : public FSM::Action {
	std::string type = RESUME_GAME_ACTION;
};
