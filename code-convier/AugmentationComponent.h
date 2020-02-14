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
		// once the cooldown stored in the list hits 0, remove 1 from the number of augmentations
		std::vector<float> damageCooldownTracker = {};
		bool multiHitAugmentation = 0;
		std::vector<float> multiHitCooldownTracker = {};
		int energyHealAugmentation = 0;
		std::vector<float> healCooldownTracker = {};
	};

}