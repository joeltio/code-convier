#pragma once

#include "Component.h"

namespace Component {

	struct Charge : public ECS::Component {
	public:
		int chargeDamage = 0;
		float chargeCooldownTimer = 0.0f;
	};

}
