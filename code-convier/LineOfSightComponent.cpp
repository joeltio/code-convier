#include "LineOfSightComponent.h"

namespace Component {

	void LineOfSight::setEntityPos(float x, float y) {
		this->corners[0].x = x;
		this->corners[0].y = y;
	}

	D3DXVECTOR2& LineOfSight::getEntityPos() {
		return this->corners[0];
	}

	void LineOfSight::setTargetPos(float x, float y) {
		this->corners[1].x = x;
		this->corners[1].y = y;
	}

	D3DXVECTOR2& LineOfSight::getTargetPos() {
		return this->corners[1];
	}

	float LineOfSight::getSqDistance() {
		float xDiff = this->corners[0].x - this->corners[1].x;
		float yDiff = this->corners[0].y - this->corners[1].y;

		return (xDiff * xDiff) + (yDiff * yDiff);
	}

}