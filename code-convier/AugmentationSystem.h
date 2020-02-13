#pragma once

#include "System.h"
#include "PlayerEntity.h"
#include "AugmentationComponent.h"
#include "PhysicsComponent.h"
#include "HealthComponent.h"
#include "AttackComponent.h"
#include <unordered_set>

namespace System {

	class Augmentation : public ECS::System {
	public:
		void update(float frameTime);
		void render();
		void releaseAll();
	};

}