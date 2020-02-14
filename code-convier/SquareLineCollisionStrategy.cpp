#include "SquareLineCollisionStrategy.h"

namespace CollisionUtil {

	SquareLineCollisionStrategy::SquareLineCollisionStrategy() {}

	bool SquareLineCollisionStrategy::isUseable(CollisionType source, CollisionType target) {
		return ((source == CollisionType::AABB && target == CollisionType::LINE) ||
				(source == CollisionType::OBB && target == CollisionType::LINE) ||
				(target == CollisionType::AABB && source == CollisionType::LINE) ||
				(target == CollisionType::OBB && source == CollisionType::LINE));
	}

	bool SquareLineCollisionStrategy::isColliding(Component::Collidable& source, Component::Collidable& target) {
		// Determine which is the line
		Component::Collidable* line = &source;
		Component::Collidable* square = &target;

		if (square->collisionType == CollisionType::LINE)
		{
			line = &target;
			square = &source;
		}

		// This is a modified version of OBB
		// Calculate source normals
		D3DXVECTOR2 squareXNormal = square->corners[1] - square->corners[0];
		D3DXVECTOR2 squareYNormal = square->corners[2] - square->corners[0];

		// Check for source x extents
		std::pair<float, float> squareXExtents = findVectorExtents(square->corners, squareXNormal);
		std::pair<float, float> lineXExtents = findVectorExtents(line->corners, squareXNormal);

		if (!doExtentsIntersect(squareXExtents, lineXExtents))
		{
			return false;
		}

		// Check for source y extents
		std::pair<float, float> sourceYExtents = findVectorExtents(square->corners, squareYNormal);
		std::pair<float, float> targetYExtents = findVectorExtents(line->corners, squareYNormal);

		if (!doExtentsIntersect(sourceYExtents, sourceYExtents))
		{
			return false;
		}

		// Calculate line normals
		D3DXVECTOR2 lineXNormal = line->corners[1] - line->corners[0];
		D3DXVECTOR2 lineYNormal(lineXNormal.y, -lineXNormal.x);

		// Check for line x extents
		squareXExtents = findVectorExtents(square->corners, lineXNormal);
		lineXExtents = findVectorExtents(line->corners, lineXNormal);

		if (!doExtentsIntersect(squareXExtents, lineXExtents))
		{
			return false;
		}

		// Check for line y extents
		sourceYExtents = findVectorExtents(square->corners, lineYNormal);
		targetYExtents = findVectorExtents(line->corners, lineYNormal);

		if (!doExtentsIntersect(sourceYExtents, targetYExtents))
		{
			return false;
		}

		return true;

	}

}
