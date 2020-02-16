#pragma once

#include "Component.h"

namespace Component {

	struct Health : ECS::Component {
		int health = 0;
		int storedHealth = 0;
	};

}