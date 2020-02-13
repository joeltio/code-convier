#pragma once

#include <d3dx9math.h>
#include "CollisionStrategy.h"

namespace CollisionUtil {

	class CircleCircleCollisionStrategy : public CollisionStrategy {
		public:
			CircleCircleCollisionStrategy();
			~CircleCircleCollisionStrategy() {};

			bool isUseable(CollisionType source, CollisionType target);
			bool isColliding(Component::Collidable source, Component::Collidable target);
	};

}
