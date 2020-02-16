#pragma once

#include "Component.h"

namespace Component {

	struct Charge : public ECS::Component {
	public:
		int damage = 0;
		float cooldown = 0.0f;
		float cooldownTimer = 0.0f;
		float chargeTime = 0.0f;
	};

}
