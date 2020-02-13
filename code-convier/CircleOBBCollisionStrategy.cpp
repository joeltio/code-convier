#include "CircleOBBCollisionStrategy.h"

namespace CollisionUtil {

	CircleOBBCollisionStrategy::CircleOBBCollisionStrategy() {
		this->sourceType = CollisionType::CIRCLE;
		this->targetType = CollisionType::OBB;
	}

	bool CircleOBBCollisionStrategy::isUseable(CollisionType source, CollisionType target) {
		return ((source == this->sourceType && target == this->targetType) ||
				(target == this->sourceType && source == this->targetType));
	}

	bool CircleOBBCollisionStrategy::isColliding(Component::Collidable& source, Component::Collidable& target) {
		// Determine which is circle and which is OBB
		Component::Collidable* circle = &source;
		Component::Collidable* obb = &target;

		if (source.collisionType == CollisionType::OBB)
		{
			circle = &target;
			obb = &source;
		}

		// Determine if the circle's center is in the voronoi region
		D3DXVECTOR2 circleCenter = circle->getCenter();

		// Calculate the OBB's normals
		D3DXVECTOR2 xNormal = obb->corners[1] - obb->corners[0];
		D3DXVECTOR2 yNormal = obb->corners[2] - obb->corners[0];

		char voronoiQuadrants[] = {2, 1, 4, 3};
		for (char i = 0; i < 4; i++)
		{
			if (getQuadrant(circleCenter, obb->corners[i], xNormal) == voronoiQuadrants[i])
			{
				return (circle->radius * circle->radius) > distance2(circleCenter, obb->corners[i]);
			}
		}

		// Check the circle and obb's extents to see if they are colliding
		std::pair<float, float> obbXExtents = findVectorExtents(obb->corners, xNormal);
		std::pair<float, float> circleXExtents {circleCenter.x - circle->radius, circleCenter.x + circle->radius};

		if (doExtentsIntersect(obbXExtents, circleXExtents))
		{
			return true;
		}

		std::pair<float, float> obbYExtents = findVectorExtents(obb->corners, yNormal);
		std::pair<float, float> circleYExtents {circleCenter.y - circle->radius, circleCenter.y + circle->radius};

		if (doExtentsIntersect(obbYExtents, circleYExtents))
		{
			return true;
		}

		return false;
	}
}
