#include "CircleCircleCollisionStrategy.h"

namespace CollisionUtil {

	CircleCircleCollisionStrategy::CircleCircleCollisionStrategy() {
		this->sourceType = CollisionType::CIRCLE;
		this->targetType = CollisionType::CIRCLE;
	}

	bool CircleCircleCollisionStrategy::isUseable(CollisionType source, CollisionType target) {
		return (source == this->sourceType && target == this->targetType);
	}

	bool CircleCircleCollisionStrategy::isColliding(Component::Collidable source, Component::Collidable target) {
		// Find the difference between the centers
		D3DXVECTOR2 centerDiff = source.getCenter() - target.getCenter();

		// Square both differences and add them together
		float total = D3DXVec2Dot(&centerDiff, &centerDiff);

		float radiiSquared = source.radius + target.radius;
		radiiSquared *= radiiSquared;

		return total < radiiSquared;
	}
}
