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

}