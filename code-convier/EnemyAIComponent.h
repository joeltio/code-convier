#pragma once

#include "Component.h"

namespace Component {

	struct EnemyAI : public ECS::Component {
	public:
		// At what distance will the enemy chase after the player
		float chaseRange = 0.0f;
		// At what distance will the enemy stop movinng towards the player
		float minRange = 0.0f;
	};

}
