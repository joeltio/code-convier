#include "EnemyMovementReducer.h"

bool EnemyMovementReducer::acceptsAction(FSM::Action& action) {
	for (std::string acceptedAction : ENEMY_MOVEMENT_ACCEPTED_ACTIONS)
	{
		if (action.type == acceptedAction)
		{
			return true;
		}
	}

	return false;
}

void EnemyMovementReducer::reduce(
	ECS::Manager* manager,
	std::unordered_map<Types::TypeId, FSM::State*> states,
	FSM::Action action
) {
	// Change the state to chase the player
	Component::EnemyMovementState& movementStateComp =
		manager->getEntityComponent<Component::EnemyMovementState>(action.dispatcherEntityId);

	if (action.type == CHASE_PLAYER_ACTION)
	{
		FSM::Reducer::changeState<EnemyMovementChaseState>(states, movementStateComp);
	}
	else if (action.type == ENEMY_ATTACK_ACTION)
	{
		// Determine the type of enemy
		ECS::Entity* enemyEntity = manager->getEntity(action.dispatcherEntityId);
		if (enemyEntity->isSameType<Entity::Enemy>())
		{
			FSM::Reducer::changeState<SkeletonAttackState>(states, movementStateComp);
		}
	}
}
