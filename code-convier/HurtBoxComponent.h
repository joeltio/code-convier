#pragma once

#include "CollidableComponent.h"

namespace Component {

	struct HurtBox : Collidable {
		HurtBox() : Collidable(CollisionUtil::CollisionType::AABB) {}
	};

}
