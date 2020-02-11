#pragma once

#include "Entity.h"
#include "Manager.h"
#include "GameStateComponent.h"
#include "GameDataComponent.h"
#include "GameMenuState.h"

namespace Entity {

	class Game : public ECS::Entity {
		public:
			static ECS::EntityIdType create(ECS::Manager* manager);
	};

}
