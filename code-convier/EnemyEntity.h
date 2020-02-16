#pragma once

#include "Entity.h"
#include "constants.h"
#include "Manager.h"
#include "graphics.h"
#include "TextureComponent.h"
#include "PhysicsComponent.h"
#include "TransformComponent.h"
#include "HealthComponent.h"
#include "JumpingComponent.h"
#include "CollidableComponent.h"
#include "LineOfSightComponent.h"
#include "AttackComponent.h"
#include "AugmentationComponent.h"
#include "AnimatableComponent.h"
#include "EnemyAIComponent.h"

namespace Entity {

	class Enemy : public ECS::Entity {
	public:
		static ECS::EntityIdType create(ECS::Manager* manager, Graphics* graphics, float x, float y);
	};

}