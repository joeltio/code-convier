#pragma once

#include "Entity.h"
#include "Manager.h"
#include "graphics.h"
#include "TextureComponent.h"
#include "TransformComponent.h"

namespace Entity {

	class MainMenu : public ECS::Entity {
	public:
		static ECS::EntityIdType create(ECS::Manager* manager, Graphics* graphics);
	};

}
