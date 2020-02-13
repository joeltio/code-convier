#pragma once

#include <vector>
#include "vectorUtil.h"
#include "CollisionStrategy.h"

namespace CollisionUtil {

	class OBBOBBCollisionStrategy : public CollisionStrategy {
		public:
			OBBOBBCollisionStrategy();
			~OBBOBBCollisionStrategy() {};

			bool isUseable(CollisionType source, CollisionType target);
			bool isColliding(Component::Collidable source, Component::Collidable target);
	};

}
