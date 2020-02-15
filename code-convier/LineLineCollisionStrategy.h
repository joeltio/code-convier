#pragma once

#include <d3dx9math.h>
#include "CollisionStrategy.h"

namespace CollisionUtil {

	class LineLineCollisionStrategy : public CollisionStrategy {
		public:
			LineLineCollisionStrategy();
			~LineLineCollisionStrategy() {};

			bool isUseable(CollisionType source, CollisionType target);
			bool isColliding(Component::Collidable& source, Component::Collidable& target);
	};

}
