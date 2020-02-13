#include "AugmentationSystem.h"

namespace System {

	void Augmentation::update(float frameTime)
	{
		// get the id of the player entity
		std::unordered_set<ECS::EntityIdType>* playerPtrs = manager->getEntities<Entity::Player>();

		for (ECS::EntityIdType id : *playerPtrs)
		{
			// get all components that are affected by the augmentations
			Component::Augmentation augmentationComponent = manager->getEntityComponent<Component::Augmentation>(id);
			Component::Health healthComponent = manager->getEntityComponent<Component::Health>(id);
			Component::Physics physicsComponent = manager->getEntityComponent<Component::Physics>(id);
			Component::Attack attackComponent = manager->getEntityComponent<Component::Attack>(id);

			healthComponent.health += augmentationComponent.energyHealAugmentation * AUGMENTATED_HEAL;
			attackComponent.attackDamage += augmentationComponent.damageAugmentation * AUGMENTATED_DAMAGE_MULTIPLIER;
			attackComponent.attackCooldownTimer -= augmentationComponent.meleeCooldownAugmentation * AUGMENTATED_COOLDOWN_REDUCTION;
			attackComponent.chargeDamage += augmentationComponent.chargeDamageAugmentation * AUGMENTATED_DAMAGE_MULTIPLIER;
			attackComponent.chargeCooldownTimer -= augmentationComponent.chargeCooldownAugemntation * AUGMENTATED_COOLDOWN_REDUCTION;
			if (augmentationComponent.multiHitAugmentation)
			{
				attackComponent.multiHits = true;
			}

			physicsComponent.velocity.x *= augmentationComponent.speedAugmentation * AUGMENTATED_SPEED_MULTIPLIER;
		}

		// applied on the last step of changing the player's values
	}

}

