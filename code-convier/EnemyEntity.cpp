#include "EnemyEntity.h"

namespace Entity {
	ECS::EntityIdType Enemy::create(ECS::Manager* manager, Graphics* graphics, float x, float y) {
		ECS::EntityIdType enemyEntityId = manager->createEntity<Enemy>();

		// add the transform component
		Component::Transform transformComponent = Component::Transform();
		transformComponent.x = x;
		transformComponent.y = y;
		manager->addComponent<Component::Transform>(enemyEntityId, transformComponent);

		// add the health component
		Component::Health healthComponent = Component::Health();
		healthComponent.health = ENEMY_HEALTH;
		manager->addComponent<Component::Health>(enemyEntityId, healthComponent);

		// add the texture component
		Component::Texture textureComponent = Component::Texture();
		textureComponent.zIndex = 3;
		if (!textureComponent.loadTexture(graphics, SKELETON_IDLE_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading enemy entity texture"));
		}
		manager->addComponent<Component::Texture>(enemyEntityId, textureComponent);

		// add the collidable component
		Component::Collidable collidableComponent = Component::Collidable();
		float width = textureComponent.totalWidth * transformComponent.scale;
		float height = textureComponent.totalHeight * transformComponent.scale;
		collidableComponent.corners.push_back(D3DXVECTOR2(x, y));
		collidableComponent.corners.push_back(D3DXVECTOR2(x + width, y));
		collidableComponent.corners.push_back(D3DXVECTOR2(x + width, y + height));
		collidableComponent.corners.push_back(D3DXVECTOR2(x, y + height));
		collidableComponent.collisionType = CollisionUtil::CollisionType::AABB;
		manager->addComponent<Component::Collidable>(enemyEntityId, collidableComponent);

		// add the attack component
		Component::Attack attackComponent = Component::Attack();
		attackComponent.attackDamage = ENEMY_ATTACK_DAMAGE;
		attackComponent.attackCooldownTimer = ENEMY_ATTACK_COOLDOWN;
		manager->addComponent<Component::Attack>(enemyEntityId, attackComponent);

		return enemyEntityId;
	}
}