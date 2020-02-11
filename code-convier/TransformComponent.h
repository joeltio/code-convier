#pragma once

#include "Component.h"

namespace Component {

	struct Transform : public ECS::Component {
		public:
			float x = 0;
			float y = 0;
			float scale = 1;
			float angle = 0;
			bool flipHorizontal = false;
			bool flipVertical = false;
	};

}
