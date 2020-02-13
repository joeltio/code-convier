#pragma once

#include "CollisionStrategy.h"

namespace CollisionUtil {

	class AABBAABBCollisionStrategy : public CollisionStrategy {
		public:
			AABBAABBCollisionStrategy();
			~AABBAABBCollisionStrategy() {};

			bool isUseable(CollisionType source, CollisionType target);
			bool isColliding(Component::Collidable source, Component::Collidable target);
	};

}
