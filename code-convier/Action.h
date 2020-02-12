#pragma once

#include <string>

#include "Entity.h"

namespace FSM {
	struct Action {
		ECS::EntityIdType dispatcherEntityId;
		std::string type = "";

		Action(std::string _type) { type = _type; }
	};

	const std::string NO_ACTION = "NO_ACTION";

	struct NoAction : public Action {
		NoAction(): Action(NO_ACTION) {}
	};
}
