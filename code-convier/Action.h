#pragma once

#include "Entity.h"

namespace FSM {
	struct Action {
		ECS::EntityIdType dispatcherEntityId;
	};
}
