#include "AABBAABBCollisionStrategy.h"

namespace CollisionUtil {

	AABBAABBCollisionStrategy::AABBAABBCollisionStrategy() {
		this->sourceType = CollisionType::AABB;
		this->targetType = CollisionType::AABB;
	}

	bool AABBAABBCollisionStrategy::isUseable(CollisionType source, CollisionType target) {
		return (source == this->sourceType && target == this->targetType);
	}

	bool AABBAABBCollisionStrategy::isColliding(Component::Collidable& source, Component::Collidable& target) {
		return !(
			// source on the left or right of target
			source.corners[1].x < target.corners[0].x || target.corners[1].x < source.corners[0].x ||
			// source above or below target
			source.corners[2].y < target.corners[0].y || target.corners[2].y < source.corners[0].y
		);
	}

}