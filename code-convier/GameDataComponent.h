#pragma once

#include "Component.h"
#include <windef.h>

namespace Component {

	class GameData : public ECS::Component {
		public:
			RECT renderRect;
	};

}
