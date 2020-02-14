#include "CircleLineCollisionStrategy.h"

namespace CollisionUtil {

	bool CircleLineCollisionStrategy::isUseable(CollisionType source, CollisionType target) {
		return ((source == CollisionType::CIRCLE && target == CollisionType::LINE) ||
				(target == CollisionType::CIRCLE && source == CollisionType::LINE));
	}

	bool CircleLineCollisionStrategy::isColliding(Component::Collidable& source, Component::Collidable& target) {
		// Determine which is the line
		Component::Collidable* line = &source;
		Component::Collidable* circle = &target;

		if (circle->collisionType == CollisionType::LINE)
		{
			line = &target;
			circle = &source;
		}

		// Calculate line normal
		D3DXVECTOR2 lineVector = line->corners[1] - line->corners[0];
		D3DXVECTOR2 lineNormal(lineVector.y, -lineVector.x);
		D3DXVECTOR2 normlineNormal;
		D3DXVec2Normalize(&normlineNormal, &lineNormal);

		// Project the circle's center onto the normal to find the distance
		float distanceFromCircle = D3DXVec2Dot(&circle->getCenter(), &normlineNormal);

		return distanceFromCircle < circle->radius;
	}

}