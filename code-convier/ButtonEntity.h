#pragma once

#include "Entity.h"
#include "Manager.h"
#include "GameStateComponent.h"
#include "GameDataComponent.h"
#include "GameMenuState.h"
#include <string>
#include "graphics.h"
#include "TextureComponent.h"
#include "TransformComponent.h"

namespace Entity {

	class Button : public ECS::Entity {
		public:
			static ECS::EntityIdType create(ECS::Manager* manager, Graphics* graphics, const char* buttonSprite, float x, float y );
	};

}
