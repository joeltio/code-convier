#pragma once

#include <utility>
#include <d3dx9math.h>

#include "CollidableComponent.h"

namespace Component {

	struct LineOfSight : public Collidable {
		LineOfSight() : Collidable(CollisionUtil::CollisionType::LINE) {
			this->corners.push_back(D3DXVECTOR2(0.0f, 0.0f));
			this->corners.push_back(D3DXVECTOR2(0.0f, 0.0f));
		}

		// Set the position of the entity that owns this line of sight component
		// It is assumed that the entity that owns this component is where the
		// line of sight is emitted from.
		void setEntityPos(float x, float y);
		// Get the position of the entity that owns this line of sight component
		D3DXVECTOR2& getEntityPos();

		// Sets the position of where the line of sight is targeted at
		void setTargetPos(float x, float y);
		// Gets the position of where the line of sight is targeted at
		D3DXVECTOR2& getTargetPos();

		float getSqDistance();
	};

}
