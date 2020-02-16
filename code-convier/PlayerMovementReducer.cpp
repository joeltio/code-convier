#include "PlayerMovementReducer.h"

bool PlayerMovementReducer::acceptsAction(FSM::Action& action) {
	for (std::string acceptedAction : MOVEMENT_ACCEPTED_ACTIONS)
	{
		if (action.type == acceptedAction)
		{
			return true;
		}
	}

	return false;
}

void PlayerMovementReducer::reduce(
	ECS::Manager* manager,
	std::unordered_map<Types::TypeId, FSM::State*> states,
	FSM::Action action
)
{
	if (action.type == MOVING_PLAYER_MOVEMENT)
	{
		// Change the state of the player entity
		ECS::EntityIdType playerEntityId = *manager->getEntities<Entity::Player>()->begin();
		Component::PlayerMovementState& movementState = manager->getEntityComponent<Component::PlayerMovementState>(playerEntityId);

		FSM::Reducer::changeState<PlayerMovementMovingState>(states, movementState);
	}

	else if (action.type == CHARGING_PLAYER_MOVEMENT)
	{
		// Change the state of the player entity
		ECS::EntityIdType playerEntityId = *manager->getEntities<Entity::Player>()->begin();
		Component::PlayerMovementState& movementState = manager->getEntityComponent<Component::PlayerMovementState>(playerEntityId);

		FSM::Reducer::changeState<PlayerMovementChargingState>(states, movementState);
	}
}
