#pragma once

#include "System.h"

namespace System {

	class Augmentation : public ECS::System {
	public:
		void update(float frameTime);
		void render();
		void releaseAll();
	};

}