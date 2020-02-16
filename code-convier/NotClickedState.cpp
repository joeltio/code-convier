#include "NotClickedState.h"

FSM::Action NotClickedState::update(float frameTime, Component::State state) {
	// Ignore if there is no button click in this frame
	if (!this->input->getMouseLButton()) {
		return FSM::NoAction();
	}

	Component::Transform transformComponent = this->manager->getEntityComponent<Component::Transform>(state.entityId);
	Component::Texture textureComponent = this->manager->getEntityComponent<Component::Texture>(state.entityId);

	int mouseX = this->input->getMouseX();
	int mouseY = this->input->getMouseY();
	FSM::Action action = FSM::NoAction();

	if ((mouseX > transformComponent.x) && (mouseX < (transformComponent.x + textureComponent.totalWidth)) &&
		(mouseY > transformComponent.y) && (mouseY < (transformComponent.y + textureComponent.totalHeight)))
	{
		Component::Text textComponent = this->manager->getEntityComponent<Component::Text>(state.entityId);

		if (textComponent.buttonText == "Start") {
			action = PrepareGameAction();
		}
		else if (textComponent.buttonText == "Credits") {
			action = ShowCreditsAction();
		}
		else if (textComponent.buttonText == "Quit") {
			action = QuitGameAction();
		}
		else if (textComponent.buttonText == "Pause") {
			action = PauseGameAction();
		}
		else if (textComponent.buttonText == "Resume") {
			action = ResumeGameAction();
		}
		else if (textComponent.buttonText == "Menu") {
			ECS::EntityIdType gameId = *this->manager->getEntities<Entity::Game>()->begin();
			Component::GameState& gameState = this->manager->getEntityComponent<Component::GameState>(gameId);
			gameState.destinationState = TO_MAIN_MENU;
			action = DestroyGameLevelAction();
		}
		else if (textComponent.buttonText == "Increased Damage") {
			Component::Augmentation augmentationComponent = this->manager->getEntityComponent<Component::Augmentation>(state.entityId);
			augmentationComponent.damageAugmentation += AUGMENTATED_DAMAGE_MULTIPLIER;
		}
		else if (textComponent.buttonText == "Energy Efficient") {
			Component::Augmentation augmentationComponent = this->manager->getEntityComponent<Component::Augmentation>(state.entityId);
			augmentationComponent.energyHealAugmentation += AUGMENTATED_HEAL;
		}
		else if (textComponent.buttonText == "MultiHit") {
			Component::Augmentation augmentationComponent = this->manager->getEntityComponent<Component::Augmentation>(state.entityId);
			augmentationComponent.multiHitAugmentation = true;
		}
	}

	if (action.type != FSM::NO_ACTION)
	{
		// Consume the click
		this->input->setMouseLButton(false);
	}

	return action;
}