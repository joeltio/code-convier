#include "CollidableComponent.h"

namespace Component {

	D3DXVECTOR2 Collidable::getCenter() {
		D3DXVECTOR2 sum(0.0f, 0.0f);
		for (D3DXVECTOR2 corner : this->corners)
		{
			sum += corner;
		}

		return sum / this->corners.size();
	}

	float Collidable::getMinExtent(char axis) {
		if (this->collisionType == CollisionUtil::CollisionType::CIRCLE)
		{
			return this->getCenter()[axis] + this->radius;
		}

		float min = INFINITY;
		for (D3DXVECTOR2 corner : this->corners)
		{
			if (corner[axis] < min)
			{
				min = corner[axis];
			}
		}

		return min;
	}

	float Collidable::getMaxExtent(char axis) {
		if (this->collisionType == CollisionUtil::CollisionType::CIRCLE)
		{
			return this->getCenter()[axis] + this->radius;
		}

		float max = 0;
		for (D3DXVECTOR2 corner : this->corners)
		{
			if (max < corner[axis])
			{
				max = corner[axis];
			}
		}

		return max;
	}

}