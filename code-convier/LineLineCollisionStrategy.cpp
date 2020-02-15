#include "LineLineCollisionStrategy.h"

namespace CollisionUtil {

	LineLineCollisionStrategy::LineLineCollisionStrategy() {
		this->sourceType = CollisionType::LINE;
		this->targetType = CollisionType::LINE;
	}

	bool LineLineCollisionStrategy::isUseable(CollisionType source, CollisionType target) {
		return (source == this->sourceType && target == this->targetType);
	}

	bool LineLineCollisionStrategy::isColliding(Component::Collidable& source, Component::Collidable& target) {
		// Never deal with line-line collision
		return false;
	}
}