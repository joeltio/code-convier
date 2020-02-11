#pragma once

#include "Component.h"

namespace Component {

	struct Jumping : public ECS::Component {
		public:
			bool isJumping = false;
	};
}
