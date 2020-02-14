#pragma once

#include <vector>
#include <unordered_set>
#include <functional>
#include <d3dx9math.h>

#include "CollisionType.h"
#include "Entity.h"
#include "Component.h"
#include "Manager.h"

namespace Component {

	struct Collidable : public ECS::Component {
		float radius;
		// Top left, top right, bottom right, bottom left. Circles only have 1 corner
		std::vector<D3DXVECTOR2> corners;

		CollisionUtil::CollisionType collisionType;

		std::unordered_set<ECS::EntityIdType> collidingWith;

		std::function<void(ECS::Manager * manager, ECS::EntityIdType entityId)> onEnter =
			[](ECS::Manager* manager, ECS::EntityIdType entityId) {};

		std::function<void(ECS::Manager * manager, ECS::EntityIdType entityId, float frameTime)> onStay =
			[](ECS::Manager* manager, ECS::EntityIdType entityId, float frameTime) {};

		std::function<void(ECS::Manager * manager, ECS::EntityIdType entityId)> onExit =
			[](ECS::Manager* manager, ECS::EntityIdType entityId) {};

		Collidable(CollisionUtil::CollisionType _collisionType) { collisionType = _collisionType; }

		D3DXVECTOR2 getCenter();

		// Gets the minimum value this collidable has for the axis.
		// 0 - x, 1 - y, 2 - z
		float getMinExtent(char axis);
		float getMaxExtent(char axis);
	};

}
