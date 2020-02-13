#pragma once
#include "Entity.h"
#include "Manager.h"
#include "graphics.h"
#include "constants.h"

#include "TransformComponent.h"
#include "TextureComponent.h"
#include "StaticCollidableComponent.h"

namespace Entity {

	class DecorativeTile : public ECS::Entity {
	public:
		static ECS::EntityIdType create(ECS::Manager* manager, Graphics* graphics, float x, float y, char type);
	};

}