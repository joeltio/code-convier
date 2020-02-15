#pragma once

#include <d3dx9.h>
#include <vector>
#include "Component.h"

namespace Component {

	struct Augmentation : public ECS::Component {
	public:
		// permanent, consistent throughout the game
		int speedAugmentation = 0;
		int meleeCooldownAugmentation = 0;
		int chargeCooldownAugemntation = 0;
		int chargeDamageAugmentation = 0;
		int chargeRangeAugmentation = 0;

		// temporary powerups
		int damageAugmentation = 0;
		bool multiHitAugmentation = 0;
		int energyHealAugmentation = 0;
	};

}