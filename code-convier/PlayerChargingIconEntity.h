#pragma once

#include "Entity.h"
#include "Manager.h"
#include "graphics.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "AnimatableComponent.h"

namespace Entity {

	class PlayerChargingIcon : public ECS::Entity {
	public:
		static ECS::EntityIdType create(
			ECS::Manager* manager,
			Graphics* graphics,
			float x,
			float y
		);
	};

}
