#pragma once

#include "CollisionType.h"
#include "CollidableComponent.h"

namespace CollisionUtil {

	class CollisionStrategy {
		protected:
			CollisionType sourceType;
			CollisionType targetType;
		public:
			virtual bool isUseable(CollisionType source, CollisionType target) = 0;
			virtual bool isColliding(Component::Collidable source, Component::Collidable target) = 0;
	};

}
