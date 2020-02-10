#pragma once

#include <string>
#include "Entity.h"

namespace FSM {
	struct Action {
		ECS::EntityIdType dispatcherEntityId;
		std::string type;
	};
}
