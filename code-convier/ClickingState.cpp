#include "ClickingState.h"

FSM::Action ClickingState::update(float frameTime, Component::State state) {
	Component::Transform transformComponent = this->manager->getEntityComponent<Component::Transform>(state.entityId);
	Component::Texture textureComponent = this->manager->getEntityComponent<Component::Texture>(state.entityId);
	Component::Text textComponent = this->manager->getEntityComponent<Component::Text>(state.entityId);

	if (this->input->getMouseLButton()) {
		if (this->input->getMouseX() > transformComponent.x&& this->input->getMouseX() < (transformComponent.x + textureComponent.totalWidth)
			&& this->input->getMouseY() > transformComponent.y&& this->input->getMouseY() < (transformComponent.y + textureComponent.totalHeight)) {
			
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
		input->setMouseLButton(FALSE);
	}
	return FSM::NoAction();
}