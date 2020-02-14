#pragma once

#include <vector>

#include "System.h"
#include "Manager.h"
#include "LineOfSightComponent.h"
#include "GameStateComponent.h"
#include "GameRunningState.h"
#include "PlayerEntity.h"

namespace System {

	class EnemyAISystem : public ECS::System {
	public:
		void update(float frameTime);
	};

}
