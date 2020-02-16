#include "PlayerAttackReducer.h"

bool PlayerAttackReducer::acceptsAction(FSM::Action& action) {
	for (std::string acceptedAction : ATTACK_ACCEPTED_ACTIONS)
	{
		if (action.type == acceptedAction)
		{
			return true;
		}
	}

	return false;
}

void PlayerAttackReducer::reduce(
	ECS::Manager* manager,
	std::unordered_map<Types::TypeId, FSM::State*> states,
	FSM::Action action
)
{
	if (action.type == PLAYER_ATTACKING)
	{
		// get the player entity
		ECS::EntityIdType playerId = *manager->getEntities<Entity::Player>()->begin();
		Component::PlayerAttackState& attackState = manager->getEntityComponent<Component::PlayerAttackState>(playerId);

		FSM::Reducer::changeState<PlayerAttackIdleState>(states, attackState);
	}

	if (action.type == PLAYER_ATTACK_IDLE)
	{
		// get the player entity
		ECS::EntityIdType playerId = *manager->getEntities<Entity::Player>()->begin();
		Component::PlayerAttackState& attackState = manager->getEntityComponent<Component::PlayerAttackState>(playerId);

		FSM::Reducer::changeState<PlayerAttackingState>(states, attackState);
	}
}