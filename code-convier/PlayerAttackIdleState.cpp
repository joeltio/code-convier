#include "PlayerAttackIdleState.h"

FSM::Action PlayerAttackIdleState::update(float frametime, Component::State stateComponent) {
	if (input->isKeyDown('J')) // attack key
	{
		// check if player attack cooldown is already up
		ECS::EntityIdType playerEntityId = stateComponent.entityId;
		Component::Attack attackComponent = manager->getEntityComponent<Component::Attack>(playerEntityId);
		if (attackComponent.cooldownTimer -= frametime < 0)
		{	
			// valid to attack
			return PlayerAttacking();
		}
	}

	return FSM::NoAction();
}