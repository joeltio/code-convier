#pragma once

#include "Entity.h"
#include "Manager.h"
#include "graphics.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "GameStateComponent.h"
#include "GamePauseState.h"

namespace Entity {

	class PauseMenu : public ECS::Entity {
	public:
		static ECS::EntityIdType create(ECS::Manager* manager, Graphics* graphics);
	};

}
