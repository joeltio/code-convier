#pragma once

#include "CollidableComponent.h"

namespace Component {

	struct StaticCollidable : public Collidable {
		StaticCollidable(CollisionUtil::CollisionType _collisionType) : Collidable(_collisionType) {}
	};

}
