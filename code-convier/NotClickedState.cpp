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
	if ((mouseX > transformComponent.x) && (mouseX < (transformComponent.x + textureComponent.totalWidth)) &&
		(mouseY > transformComponent.y) && (mouseY < (transformComponent.y + textureComponent.totalHeight)))
	{
		Component::Text textComponent = this->manager->getEntityComponent<Component::Text>(state.entityId);

		if (textComponent.buttonText == "Start") {
			return PrepareGameAction();
		}
		else if (textComponent.buttonText == "Credits") {
			return ShowCreditsAction();
		}
		else if (textComponent.buttonText == "Quit") {
			return QuitGameAction();
		}
		else if (textComponent.buttonText == "Pause") {
			return PauseGameAction();
		}
		else if (textComponent.buttonText == "Resume") {
			return ResumeGameAction();
		}
		else {
			return PrepareMenuAction();
		}
	}

	return FSM::NoAction();
}