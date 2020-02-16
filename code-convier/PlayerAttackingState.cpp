#include "PlayerAttackingState.h"

FSM::Action PlayerAttackingState::update(float frameTime, Component::State stateComponent) {
	// Get the direction the entity is facing, using right as the benchmark
	ECS::EntityIdType playerId = *manager->getEntities<Entity::Player>()->begin();
	bool facingRight = manager->getEntityComponent<Component::Transform>(playerId).flipHorizontal;

	// Create the hitboxes


	return FSM::NoAction();
}
