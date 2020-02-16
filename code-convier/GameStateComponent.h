#pragma once

#include "StateComponent.h"

namespace Component {
	struct GameState : public Component::State {
		RECT renderRect;
		int destinationState;
	};
}
