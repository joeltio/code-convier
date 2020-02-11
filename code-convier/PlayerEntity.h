#pragma once

#include "Entity.h"
#include "Manager.h"
#include "PositionComponent.h"
#include "PhysicsComponent.h"

namespace Entity {

	class Player : public ECS::Entity {
	public:
		static ECS::EntityIdType create(ECS::Manager* manager);
	};

}