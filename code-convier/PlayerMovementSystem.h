#pragma once

#include <vector>
#include <unordered_set>

#include "System.h"
#include "Manager.h"
#include "PhysicsComponent.h"

namespace System {

	class PlayerMovement : public ECS::System {
	public:
		void update(float frameTime);
	};

}