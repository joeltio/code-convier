#pragma once

#include "Component.h"

namespace Component {

	struct HealthRecover : ECS::Component {
		int health = 0;
	};

}