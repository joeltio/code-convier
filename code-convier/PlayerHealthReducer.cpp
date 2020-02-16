#include "PlayerHealthReducer.h"

bool PlayerHealthReducer::acceptsAction(FSM::Action& action) {
	for (std::string acceptedAction : HEALTH_ACCEPTED_ACTIONS)
	{
		if (action.type == acceptedAction)
		{
			return true;
		}
	}

	return false;
}

void PlayerHealthReducer::reduce(
	ECS::Manager* manager,
	std::unordered_map<Types::TypeId, FSM::State*> states,
	FSM::Action action
)
{
	if (action.type == IDLE_PLAYER_HEALTH)
	{
		// get the player entity and shift its health state
		ECS::EntityIdType playerEntityId = *manager->getEntities<Entity::Player>()->begin();
		Component::PlayerHealthState& healthState = manager->getEntityComponent<Component::PlayerHealthState>(playerEntityId);

		FSM::Reducer::changeState<PlayerHealthIdleState>(states, healthState);
	}

	if (action.type == REPLENISHING_PLAYER_HEALTH)
	{
		// get the player entity and shift its health state
		ECS::EntityIdType playerEntityId = *manager->getEntities<Entity::Player>()->begin();
		Component::PlayerHealthState& healthState = manager->getEntityComponent<Component::PlayerHealthState>(playerEntityId);

		FSM::Reducer::changeState<PlayerHealthReplenishingState>(states, healthState);
	}

	if (action.type == DEAD_PLAYER_HEALTH)
	{
		// get the player entity and shift its health state
		ECS::EntityIdType playerEntityId = *manager->getEntities<Entity::Player>()->begin();
		Component::PlayerHealthState& healthState = manager->getEntityComponent<Component::PlayerHealthState>(playerEntityId);

		FSM::Reducer::changeState<PlayerDeathState>(states, healthState);
	}
}