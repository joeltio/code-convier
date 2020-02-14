#pragma once

#include "vectorUtil.h"
#include "CollisionStrategy.h"

namespace CollisionUtil {

	class CircleLineCollisionStrategy  : public CollisionStrategy {
		public:
			CircleLineCollisionStrategy();
			~CircleLineCollisionStrategy() {};

			bool isUseable(CollisionType source, CollisionType target);
			bool isColliding(Component::Collidable& source, Component::Collidable& target);
	};

}
