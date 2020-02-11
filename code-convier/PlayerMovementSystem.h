#pragma once

#include <vector>
#include <unordered_set>

#include "System.h"
#include "Manager.h"
#include "PhysicsComponent.h"

namespace System { 

	class Movement : public ECS::System {
	public:
		void update(float frameTime);
	};

}

// player jumps with a constant V value