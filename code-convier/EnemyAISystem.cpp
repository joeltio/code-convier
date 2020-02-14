#include "EnemyAISystem.h"

namespace System {

	void EnemyAISystem::update(float frameTime) {
		// Check the current game state
		Component::GameState& gameStateComponent = *this->manager->getComponents<Component::GameState>()->begin();
		if (gameStateComponent.state != Types::toTypeId<GameRunningState>())
		{
			return;
		}

		// Get all line of sight components
		std::vector<Component::LineOfSight>* losComponents = this->manager->getComponents<Component::LineOfSight>();

		// Get the player entity
		// To extend to multi-player, use multiple los components that track all the players
		ECS::EntityIdType playerEntityId = *this->manager->getEntities<Entity::Player>()->begin();
		// Get the player's position
		Component::Transform& playerTransformComponent =
			this->manager->getEntityComponent<Component::Transform>(playerEntityId);

		for (Component::LineOfSight& losComponent : *losComponents)
		{
			// Get the position of the entity that owns the los component
			Component::Transform& transformComponent =
				this->manager->getEntityComponent<Component::Transform>(losComponent.entityId);

			// Set the start point to the current entity's position
			losComponent.setEntityPos(transformComponent.x, transformComponent.y);

			// Set the end point to the player's position
			losComponent.setTargetPos(playerTransformComponent.x, playerTransformComponent.y);
		}
	}
}
