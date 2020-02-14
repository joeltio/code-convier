#pragma once

#include <d3dx9.h>
#include "System.h"
#include "Manager.h"
#include "graphics.h"
#include "input.h"
#include "PhysicsComponent.h"
#include "CollidableComponent.h"
#include "TransformComponent.h"

namespace System {

	class Physics : public ECS::System {
		public:
			void update(float frameTime);
			void render();
			void releaseAll();
	};

}
