#pragma once

#include <utility>
#include <d3dx9math.h>

#include "CollidableComponent.h"

namespace Component {

	struct LineOfSight : public Collidable {
		LineOfSight() : Collidable(CollisionUtil::CollisionType::LINE) {}
	};

}
