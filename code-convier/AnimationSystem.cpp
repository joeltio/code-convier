#include "AnimationSystem.h"

namespace System {

	void Animation::update(float frameTime) {
		// Get all animatable components
		std::vector<Component::Animatable>* componentsPtr =
			this->manager->getComponents<Component::Animatable>();

		for (Component::Animatable& animatableComponent : *componentsPtr)
		{
			// Ignore completed animations
			if (animatableComponent.isComplete)
			{
				continue;
			}

			// Decrease the animatable component's time left
			animatableComponent.frameTimeLeft -= frameTime;
			if (animatableComponent.frameTimeLeft <= 0)
			{
				// It is possible that more than 1 frameInterval has passed.
				// Calculate the number of frames passed
				// Since the division of float is stored as an int, the result is floored
				int framesPassed = ((-animatableComponent.frameTimeLeft) / animatableComponent.frameDelay) + 1;
				animatableComponent.currentFrame += framesPassed;

				// Reset the frame time left
				animatableComponent.frameTimeLeft += (framesPassed + 1) * animatableComponent.frameDelay;
			}

			// Update the frame to the first frame if it is past the end frame
			if (animatableComponent.currentFrame > animatableComponent.endFrame)
			{
				if (animatableComponent.loopForever)
				{
					animatableComponent.currentFrame = animatableComponent.startFrame;
				}
				else
				{
					animatableComponent.isComplete = true;
					continue;
				}
			}

			// Get the corresponding texture component
			Component::Texture& textureComponent =
				this->manager->getEntityComponent<Component::Texture>(animatableComponent.entityId);

			// Since totalWidth and columns are int, this performs floor division
			int width = textureComponent.totalWidth / animatableComponent.columns;
			int height = textureComponent.totalHeight / animatableComponent.rows;

			// Calculate the row and column of the currentFrame
			int currentCol = ((animatableComponent.currentFrame - 1) % animatableComponent.columns) + 1;
			int currentRow = ((animatableComponent.currentFrame - 1) / animatableComponent.columns) + 1;

			// Set the viewableRect to the current frame
			textureComponent.viewableRect.left = (currentCol - 1) * width;
			textureComponent.viewableRect.right = currentCol * width;
			textureComponent.viewableRect.top = (currentRow - 1) * height;
			textureComponent.viewableRect.bottom = currentRow * height;
		}
	}

}