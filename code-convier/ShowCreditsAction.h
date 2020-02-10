#pragma once

#include <string>
#include "Action.h"

const std::string SHOW_CREDITS_ACTION = "SHOW_CREDITS_ACTION";

struct ShowCreditsAction : public FSM::Action {
	std::string type = SHOW_CREDITS_ACTION;
};