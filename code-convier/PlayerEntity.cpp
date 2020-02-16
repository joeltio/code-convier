#include "PlayerEntity.h"

namespace Entity {
	ECS::EntityIdType Player::create(ECS::Manager* manager, Graphics* graphics, float x, float y) {
		ECS::EntityIdType entityId = manager->createEntity<Player>();

		// add the physics component
		Component::Physics physicsComponent = Component::Physics();
		physicsComponent.acceleration.y = GRAVITY_ACCELERATION;
		manager->addComponent<Component::Physics>(entityId, physicsComponent);

		// add the transform component
		Component::Transform transformComponent = Component::Transform();
		transformComponent.x = x;
		transformComponent.y = y;
		transformComponent.scale = 1;
		manager->addComponent<Component::Transform>(entityId, transformComponent);

		// add the health component
		Component::Health healthComponent = Component::Health();
		healthComponent.health = PLAYER_HEALTH;
		manager->addComponent<Component::Health>(entityId, healthComponent);

		// add the texture component
		Component::Texture textureComponent = Component::Texture();
		textureComponent.zIndex = 3;
		if (!textureComponent.loadTexture(graphics, PLAYER_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading player entity texture"));
		}
		manager->addComponent<Component::Texture>(entityId, textureComponent);

		// add animation component
		Component::Animatable animatableComponent = Component::Animatable();
		animatableComponent.columns = 10;
		animatableComponent.rows = 1;
		animatableComponent.startFrame = 1;
		animatableComponent.endFrame = 10;
		animatableComponent.currentFrame = 1;
		animatableComponent.frameDelay = 1000;
		manager->addComponent<Component::Animatable>(entityId, animatableComponent);

		// add the collidable component
		Component::Collidable collidableComponent = Component::Collidable(CollisionUtil::CollisionType::AABB);
		float width = textureComponent.totalWidth / animatableComponent.columns * transformComponent.scale;
		float height = textureComponent.totalHeight / animatableComponent.rows * transformComponent.scale;
		collidableComponent.corners.push_back(D3DXVECTOR2(x, y));
		collidableComponent.corners.push_back(D3DXVECTOR2(x + width, y));
		collidableComponent.corners.push_back(D3DXVECTOR2(x + width, y + height));
		collidableComponent.corners.push_back(D3DXVECTOR2(x, y + height));
		manager->addComponent<Component::Collidable>(entityId, collidableComponent);

		// add the attack component
		Component::Attack attackComponent = Component::Attack();
		attackComponent.damage = PLAYER_DAMAGE;
		attackComponent.cooldown = PLAYER_ATTACK_COOLDOWN;
		attackComponent.range = PLAYER_ATTACK_RANGE;
		manager->addComponent<Component::Attack>(entityId, attackComponent);

		// add the charging component
		Component::Charge chargeComponent = Component::Charge();
		chargeComponent.cooldown = PLAYER_CHARGE_COOLDOWN;
		chargeComponent.damage = PLAYER_CHARGE_DAMAGE;
		manager->addComponent<Component::Charge>(entityId, chargeComponent);

		// add the Jumping component
		Component::Jumping jumpingComponent = Component::Jumping();
		manager->addComponent<Component::Jumping>(entityId, jumpingComponent);

		// add the movement state component
		Component::PlayerMovementState movementStateComponent = Component::PlayerMovementState {
			entityId,
			true,
			Types::toTypeId<PlayerMovementMovingState>()
		};
		manager->addComponent<Component::PlayerMovementState>(entityId, movementStateComponent);

		// add the attack state component
		Component::PlayerAttackState attackStateComponent = Component::PlayerAttackState {
			entityId,
			true,
			Types::toTypeId<PlayerAttackIdleState>()
		};
		manager->addComponent<Component::PlayerAttackState>(entityId, attackStateComponent);

		// add the health state component
		Component::PlayerHealthState healthStateComponent = Component::PlayerHealthState{
			entityId,
			true,
			Types::toTypeId<PlayerHealthIdleState>()
		};

		return entityId;
	}
}