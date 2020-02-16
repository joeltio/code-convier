#include "AugmentationSystem.h"

namespace System {

	void Augmentation::update(float frameTime)
	{
		// get the id of the player entity
		std::unordered_set<ECS::EntityIdType>* playerPtrs = manager->getEntities<Entity::Player>();
		if (playerPtrs->empty())
		{
			return;
		}

		std::vector<Component::Augmentation>* augmentationPtrs = manager->getComponents<Component::Augmentation>();
		Component::Augmentation& augmentationComponent = augmentationPtrs->at(0);
		for (ECS::EntityIdType id : *playerPtrs)
		{
			// get all components that are affected by the augmentations
			Component::Health& healthComponent = manager->getEntityComponent<Component::Health>(id);
			Component::Physics& physicsComponent = manager->getEntityComponent<Component::Physics>(id);
			Component::Attack& attackComponent = manager->getEntityComponent<Component::Attack>(id);
			Component::Charge& chargeComponent = manager->getEntityComponent<Component::Charge>(id);

			// set as base values to ensure its not compounded
			healthComponent.health = PLAYER_HEALTH + augmentationComponent.energyHealAugmentation * AUGMENTATED_HEAL;
			attackComponent.damage = PLAYER_DAMAGE + augmentationComponent.damageAugmentation * AUGMENTATED_DAMAGE_MULTIPLIER;
			attackComponent.cooldown = PLAYER_ATTACK_COOLDOWN - augmentationComponent.meleeCooldownAugmentation * AUGMENTATED_COOLDOWN_REDUCTION;
			chargeComponent.damage = PLAYER_CHARGE_DAMAGE + augmentationComponent.chargeDamageAugmentation * AUGMENTATED_DAMAGE_MULTIPLIER;
			chargeComponent.cooldown = PLAYER_CHARGE_COOLDOWN - augmentationComponent.chargeCooldownAugemntation * AUGMENTATED_COOLDOWN_REDUCTION;
			if (augmentationComponent.multiHitAugmentation)
			{
				attackComponent.multiHits = true;
			}

			physicsComponent.velocity.x = physicsComponent.velocity.x * augmentationComponent.speedAugmentation * AUGMENTATED_SPEED_MULTIPLIER;
		}

		// applied on the last step of changing the player's values
	}

}

