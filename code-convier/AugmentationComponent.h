#pragma once

#include <d3dx9.h>
#include "Component.h"

namespace Component {

	struct Augmentation : public ECS::Component {
	public:
		int speedAugmentation = 0;
		int meleeCooldownAugmentation = 0;
		int chargeCooldownAugemntation = 0;
		int chargeDamageAugmentation = 0;
		int chargeRangeAugmentation = 0;
		int damageAugmentation = 0;
		int multiHitAugmentation = 0;
		int energyEfficiencyAugmentation = 0;
	};

}