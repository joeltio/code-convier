#pragma once

#include "Entity.h"
#include "Manager.h"
#include "GameStateComponent.h"
#include "GameMenuState.h"
#include "AugmentationComponent.h"

namespace Entity {

	class Game : public ECS::Entity {
		public:
			static ECS::EntityIdType create(ECS::Manager* manager);
	};

}
