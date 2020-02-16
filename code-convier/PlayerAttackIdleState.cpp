#include "PlayerAttackIdleState.h"

FSM::Action PlayerAttackIdleState::update(float frametime, Component::State stateComponent) {
	if (input->isKeyDown('J')) // attack key
	{
		// check if player attack cooldown is already up
		ECS::EntityIdType playerEntityId = stateComponent.entityId;
		Component::Attack attackComponent = manager->getEntityComponent<Component::Attack>(playerEntityId);
		attackComponent.cooldownTimer -= frametime;

		if (attackComponent.cooldownTimer <= 0)
		{	
			// valid to attack
			Component::Texture& textureComponent = manager->getEntityComponent<Component::Texture>(playerEntityId);
			textureComponent.zIndex = 2;
			if (!textureComponent.loadTexture(graphics, PLAYER_MELEE_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading player melee attack texture"));
			}

			Component::Animatable& animatableComponent = manager->getEntityComponent<Component::Animatable>(playerEntityId);
			animatableComponent.columns = 8;
			animatableComponent.rows = 1;
			animatableComponent.startFrame = 1;
			animatableComponent.endFrame = 8;
			animatableComponent.currentFrame = 1;
			animatableComponent.frameDelay = 1000;
			Component::Transform& transformComponent = manager->getEntityComponent<Component::Transform>(playerEntityId);
			transformComponent.scale = 0.22 * SCALE_FACTOR;
			return PlayerAttacking();
		}
	}

	return FSM::NoAction();
}