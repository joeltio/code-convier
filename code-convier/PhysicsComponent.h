#pragma once

#include <d3dx9.h>
#include "Component.h"

namespace Component {

	struct Physics : ECS::Component {
		D3DXVECTOR2 velocity = D3DXVECTOR2(0.0f, 0.0f);
	};

}