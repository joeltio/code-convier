#pragma once

#include "Component.h"
#include <string>

namespace Component {

	struct Text : ECS::Component {
		std::string buttonText;
	};

}