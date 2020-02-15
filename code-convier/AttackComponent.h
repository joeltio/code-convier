#pragma once

#include "Component.h"

namespace Component {

	struct Attack : public ECS::Component {
	public:
		int damage = 0;
		// Time between attacks
		float cooldown = 0.0f;
		float cooldownTimer = 0.0f;
		// Time until attack starts
		float initialDelay = 0.0f;
		float initialDelayTimer = 0.0f;
		// Whether the attack can hit multiple people
		bool multiHits = false;
	};

}
