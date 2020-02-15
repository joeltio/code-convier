#pragma once

#include "Entity.h"
#include "Manager.h"
#include "graphics.h"
#include <string>
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "TextComponent.h"
#include "AugmentationComponent.h"
#include "ClickStateComponent.h"
#include "NotClickedState.h"

namespace Entity {

	class Button : public ECS::Entity {
		public:
			static ECS::EntityIdType create(
				ECS::Manager* manager,
				Graphics* graphics,
				const char* buttonsprites,
				std::string buttonText,
				float x,
				float y,
				bool centerX,
				bool centerY
			);
	};

}
