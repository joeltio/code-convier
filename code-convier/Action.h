#pragma once

#include <string>
#include "Entity.h"

namespace FSM {
	struct Action {
		ECS::EntityIdType dispatcherEntityId;
		std::string type;
	};

	const std::string NO_ACTION = "NO_ACTION";

	struct NoAction : public Action {
		std::string type = NO_ACTION;
	};
}
