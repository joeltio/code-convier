#include "AABBCircleCollisionStrategy.h"

namespace CollisionUtil {

	AABBCircleCollisionStrategy::AABBCircleCollisionStrategy() {
		this->sourceType = CollisionType::AABB;
		this->targetType = CollisionType::CIRCLE;
	}

	bool AABBCircleCollisionStrategy::isUseable(CollisionType source, CollisionType target) {
		return ((source == this->sourceType && target == this->targetType) ||
				(target == this->sourceType && source == this->targetType));
	}

	bool AABBCircleCollisionStrategy::isColliding(Component::Collidable& source, Component::Collidable& target) {
		// Determine which is circle and which is aabb
		Component::Collidable* circle = &source;
		Component::Collidable* aabb = &target;

		if (source.collisionType == CollisionType::AABB)
		{
			circle = &target;
			aabb = &source;
		}

		// Check if the circle is in the voronoi region
		D3DXVECTOR2 circleCenter = circle->getCenter();
		char voronoiQuadrants[] = {2, 1, 4, 3};

		for (char i = 0; i < 4; i++)
		{
			if (getQuadrant(circleCenter, aabb->corners[i]) == voronoiQuadrants[i])
			{
				return (circle->radius * circle->radius) > distance2(circleCenter, aabb->corners[i]);
			}
		}

		// Find the normals of aabb
		D3DXVECTOR2 xNormal = aabb->corners[1] - aabb->corners[0];
		D3DXVECTOR2 yNormal = aabb->corners[2] - aabb->corners[0];

		std::pair<float, float> aabbXExtents = findVectorExtents(aabb->corners, xNormal);
		std::pair<float, float> circleXExtents {circleCenter.x - circle->radius, circleCenter.x + circle->radius};

		if (doExtentsIntersect(aabbXExtents, circleXExtents))
		{
			return true;
		}

		std::pair<float, float> aabbYExtents = findVectorExtents(aabb->corners, yNormal);
		std::pair<float, float> circleYExtents {circleCenter.y - circle->radius, circleCenter.y + circle->radius};

		if (doExtentsIntersect(aabbYExtents, circleYExtents))
		{
			return true;
		}

		return false;
	}

}