#pragma once

#include "Component.h"

namespace Component {

	struct Attack : public ECS::Component {
	public:
		int attackDamage = 0;
		float attackCooldownTimer = 0.0f;
		bool multiHits = false;
	};

}
