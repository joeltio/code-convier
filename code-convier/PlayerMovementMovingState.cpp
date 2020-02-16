#include "PlayerMovementMovingState.h"

FSM::Action PlayerMovementMovingState::update(float frametime, Component::State stateComponent)
{
	ECS::EntityIdType referenceId = stateComponent.entityId; // for use later
	Component::Physics& physicsComponent = manager->getEntityComponent<Component::Physics>(referenceId);
	Component::Transform& transformComponent = manager->getEntityComponent<Component::Transform>(referenceId);
	Component::Jumping& jumpingComponent = manager->getEntityComponent<Component::Jumping>(referenceId);

	// reset the x velocity in the state before checking for input
	physicsComponent.velocity.x = 0;

	// Set icon frames to 1
	std::unordered_set<ECS::EntityIdType> playerRunningEntityIds = *this->manager->getEntities<Entity::PlayerRunningIcon>();
	for (ECS::EntityIdType playerRunningEntityId : playerRunningEntityIds)
	{
		Component::Animatable& animatableComponent = manager->getEntityComponent<Component::Animatable>(playerRunningEntityId);
		animatableComponent.currentFrame = 1;
		animatableComponent.startFrame = 1;
	}

	std::unordered_set<ECS::EntityIdType> playerChargingEntityIds = *this->manager->getEntities<Entity::PlayerChargingIcon>();
	for (ECS::EntityIdType playerChargingEntityId : playerChargingEntityIds)
	{
		Component::Animatable& animatableComponent = manager->getEntityComponent<Component::Animatable>(playerChargingEntityId);
		animatableComponent.currentFrame = 1;
		animatableComponent.startFrame = 1;
	}

	// check if the entity is already jumping or not
	if (!jumpingComponent.isJumping)
	{
		// reset the y velocity if the player is not jumping
		physicsComponent.velocity.y = 0;
		// handle the jump velocity first
		if (input->isKeyDown('W')) // jump
		{
			physicsComponent.velocity.y = JUMP_SPEED * SCALE_FACTOR;
			jumpingComponent.isJumping = true;
		}
	}

	// check for player movement button clicks
	if (input->isKeyDown('A')) // left
	{
		transformComponent.flipHorizontal = true;
		physicsComponent.velocity.x = -PLAYER_SPEED * SCALE_FACTOR;
	}

	if (input->isKeyDown('D')) // right
	{
		transformComponent.flipHorizontal = false;
		physicsComponent.velocity.x = PLAYER_SPEED * SCALE_FACTOR;
	}

	// mutually exclusive with charging, and walking 
	if (input->isKeyDown(SHIFT_KEY))
	{
		Component::Health& healthComponent = manager->getEntityComponent<Component::Health>(stateComponent.entityId);
		// check for direction
		if (input->isKeyDown('A')) // left run
		{
			transformComponent.flipHorizontal = true;
			physicsComponent.velocity.x = -PLAYER_SPEED * SCALE_FACTOR * RUN_MULTIPLIER;
			healthComponent.health -= RUNNING_HEATLH_TICK * frametime;
		}

		else if (input->isKeyDown('D')) // right run
		{
			transformComponent.flipHorizontal = false;
			physicsComponent.velocity.x = PLAYER_SPEED * SCALE_FACTOR * RUN_MULTIPLIER;
			healthComponent.health -= RUNNING_HEATLH_TICK * frametime;
		}

		std::unordered_set<ECS::EntityIdType> playerRunningEntityIds = *this->manager->getEntities<Entity::PlayerRunningIcon>();
		for (ECS::EntityIdType playerRunningEntityId : playerRunningEntityIds)
		{
			Component::Animatable& animatableComponent = manager->getEntityComponent<Component::Animatable>(playerRunningEntityId);
			animatableComponent.currentFrame = 2;
			animatableComponent.startFrame = 2;
		}
	}

	// mutually exclusive with running and walking
	if (input->isKeyDown('K')) // charge
	{
		Component::Charge& chargeComponent = manager->getEntityComponent<Component::Charge>(stateComponent.entityId);
		chargeComponent.cooldownTimer -= frametime;
		// ignore if the charge is still on cooldown
		if (chargeComponent.cooldownTimer <= 0)
		{
			int attackDirectionSign = (transformComponent.flipHorizontal) ? 1 : -1;
			Component::Health& healthComponent = manager->getEntityComponent<Component::Health>(stateComponent.entityId);

			physicsComponent.velocity.x = PLAYER_CHARGE_SPEED * attackDirectionSign * SCALE_FACTOR;
			healthComponent.health -= CHARGE_HEALTH_TICK; // initial tick
			chargeComponent.cooldownTimer = chargeComponent.cooldown;
			chargeComponent.chargeTime = PLAYER_CHARGE_TIMER;

			std::unordered_set<ECS::EntityIdType> playerChargingEntityIds = *this->manager->getEntities<Entity::PlayerChargingIcon>();
			for (ECS::EntityIdType playerChargingEntityId : playerChargingEntityIds)
			{
				Component::Animatable& animatableComponent = manager->getEntityComponent<Component::Animatable>(playerChargingEntityId);
				animatableComponent.currentFrame = 2;
				animatableComponent.startFrame = 2;
			}

			return ChargingPlayerMovement();
		}
	}
}
 