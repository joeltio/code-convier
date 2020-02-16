#pragma once

#include "StateComponent.h"
#include "constants.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace Component {
	struct GameLevel : public Component::State {
		bool isOnSamePlatform(float x1, float y1, float x2, float y2);
	};
}
