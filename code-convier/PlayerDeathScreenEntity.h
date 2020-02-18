#pragma once

#include "Entity.h"
#include "Manager.h"
#include "graphics.h"
#include "TextureComponent.h"
#include "TransformComponent.h"

#include "GameStateComponent.h"
#include "GamePlayerDeathState.h"

namespace Entity {

	class PlayerDeathScreen : public ECS::Entity {
	public:
		static ECS::EntityIdType create(ECS::Manager* manager, Graphics* graphics);
	};

}
