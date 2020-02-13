#pragma once

#include "Entity.h"
#include "constants.h"
#include "Manager.h"
#include "graphics.h"
#include "TextureComponent.h"
#include "PlayerEntity.h"
#include "TransformComponent.h"
#include "HealthComponent.h"

namespace Entity {

	class Healthbar : public ECS::Entity {
	public:
		static ECS::EntityIdType create(ECS::Manager* manager, Graphics* graphics, float x, float y);
	};

}