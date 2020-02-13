#pragma once

#include <vector>

#include "System.h"
#include "Manager.h"
#include "CollisionStrategy.h"
#include "AABBAABBCollisionStrategy.h"
#include "AABBCircleCollisionStrategy.h"
#include "AABBOBBCollisionStrategy.h"
#include "CircleCircleCollisionStrategy.h"
#include "CircleOBBCollisionStrategy.h"
#include "OBBOBBCollisionStrategy.h"
#include "StaticCollidableComponent.h"
#include "CollidableComponent.h"
#include "StaticCollidableComponent.h"
#include "PhysicsComponent.h"

namespace System {

	class Collision : public ECS::System {
		private:
			std::vector<CollisionUtil::CollisionStrategy*> strategies;
			// Searches for a strategy to use to check for collision between a and b
			bool colliding(Component::Collidable& a, Component::Collidable& b);
			// Tests for collision and updates a and b accordingly
			void handleCollision(Component::Collidable& a, Component::Collidable& b, float frameTime);

		public:
			void initialize(ECS::Manager* manager, Graphics* graphics, Input* input);
			void update(float frameTime);
			void releaseAll();
	};

}
