#pragma once

#include "Entity.h"
#include "Manager.h"
#include "graphics.h"
#include <string>
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "TextComponent.h"

namespace Entity {

	class Button : public ECS::Entity {
		public:
			static ECS::EntityIdType create(ECS::Manager* manager, Graphics* graphics, const char* buttonSprite, std::string buttonText, float x, float y );
	};

}
