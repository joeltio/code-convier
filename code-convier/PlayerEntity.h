#pragma once

#include "Entity.h"
#include "Manager.h"
#include "PhysicsComponent.h"
#include "TransformComponent.h"
#include "HealthComponent.h"

namespace Entity {

	class Player : public ECS::Entity {
	public:
		static ECS::EntityIdType create(ECS::Manager* manager);
	};

}