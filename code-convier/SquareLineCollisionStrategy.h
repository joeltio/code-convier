#pragma once

#include "vectorUtil.h"
#include "CollisionStrategy.h"

namespace CollisionUtil {

	class SquareLineCollisionStrategy : public CollisionStrategy {
		public:
			SquareLineCollisionStrategy();
			~SquareLineCollisionStrategy() {};

			bool isUseable(CollisionType source, CollisionType target);
			bool isColliding(Component::Collidable& source, Component::Collidable& target);
	};

}
