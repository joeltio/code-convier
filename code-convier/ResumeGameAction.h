#pragma once

#include <string>
#include "Action.h"

const std::string RESUME_GAME_ACTION = "RESUME_GAME_ACTION";

struct ResumeGameAction : public FSM::Action {
	ResumeGameAction(): FSM::Action(RESUME_GAME_ACTION) {}
};
