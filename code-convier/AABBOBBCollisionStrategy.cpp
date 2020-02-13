#include "AABBOBBCollisionStrategy.h"

namespace CollisionUtil {

	AABBOBBCollisionStrategy::AABBOBBCollisionStrategy() {
		this->sourceType = CollisionType::AABB;
		this->targetType = CollisionType::OBB;
	}

	bool AABBOBBCollisionStrategy::isUseable(CollisionType source, CollisionType target) {
		return ((source == this->sourceType && target == this->targetType) ||
				(target == this->sourceType && source == this->targetType));
	}

	bool AABBOBBCollisionStrategy::isColliding(Component::Collidable source, Component::Collidable target) {
		// Note that this strategy uses the same code as OBBOBB

		// Calculate source normals
		D3DXVECTOR2 sourceXNormal = source.corners[1] - source.corners[0];
		D3DXVECTOR2 sourceYNormal = source.corners[2] - source.corners[0];

		// Check for source x extents
		std::pair<float, float> sourceXExtents = findVectorExtents(source.corners, sourceXNormal);
		std::pair<float, float> targetXExtents = findVectorExtents(target.corners, sourceXNormal);

		if (!doExtentsIntersect(sourceXExtents, targetXExtents))
		{
			return false;
		}

		// Check for source y extents
		std::pair<float, float> sourceYExtents = findVectorExtents(source.corners, sourceYNormal);
		std::pair<float, float> targetYExtents = findVectorExtents(target.corners, sourceYNormal);

		if (!doExtentsIntersect(sourceYExtents, sourceYExtents))
		{
			return false;
		}

		// Calculate target normals
		D3DXVECTOR2 targetXNormal = target.corners[1] - target.corners[0];
		D3DXVECTOR2 targetYNormal = target.corners[2] - target.corners[0];

		// Check for target x extents
		sourceXExtents = findVectorExtents(source.corners, targetXNormal);
		targetXExtents = findVectorExtents(target.corners, targetXNormal);

		if (!doExtentsIntersect(sourceXExtents, targetXExtents))
		{
			return false;
		}

		// Check for target y extents
		sourceYExtents = findVectorExtents(source.corners, targetYNormal);
		targetYExtents = findVectorExtents(target.corners, targetYNormal);

		if (!doExtentsIntersect(sourceYExtents, targetYExtents))
		{
			return false;
		}

		return true;
	}
}