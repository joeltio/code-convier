#pragma once

#include "Component.h"

namespace Component {

	struct Physics : ECS::Component {
		float velocityX = 0.0f;
		float velocityY = 0.0f;
	};

}