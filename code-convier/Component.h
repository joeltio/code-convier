#pragma once

#include "entity.h"

namespace ECS {

struct Component {
	EntityIdType entityId;
	bool isActive = true;
};

}
