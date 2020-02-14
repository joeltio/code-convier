#pragma once

#include "Entity.h"
#include "Manager.h"
#include "graphics.h"
#include "constants.h"

#include "PlayerEntity.h"

#include "TransformComponent.h"
#include "TextureComponent.h"
#include "StaticCollidableComponent.h"
#include "HealthRecoverComponent.h"

namespace Entity {

	class EnergyOrb : public ECS::Entity {
	public:
		static ECS::EntityIdType create(ECS::Manager* manager, Graphics* graphics, float x, float y, int energy);
	};

}