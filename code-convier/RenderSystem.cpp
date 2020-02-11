#include "RenderSystem.h"

namespace System {

	void Render::render() {
		this->graphics->spriteBegin();

		LP_SPRITE sprite = this->graphics->getSprite();

		// Get all texture components
		std::vector<Component::Texture>* componentsPtr =
			this->manager->getComponents<Component::Texture>();

		// Get the game state entity
		Component::GameData gameState = this->manager->getComponents<Component::GameData>()->at(0);

		for (Component::Texture textureComponent : *componentsPtr)
		{
			// Ignore non-visible components
			if (!textureComponent.visible) {
				continue;
			}

			// Get the transform component
			Component::Transform transformComponent =
				this->manager->getEntityComponent<Component::Transform>(textureComponent.entityId);

			// Offset the position by the current render game state
			transformComponent.x -= gameState.renderRect.left;
			transformComponent.y -= gameState.renderRect.top;

			long viewableWidth = textureComponent.viewableRect.right - textureComponent.viewableRect.left;
			long viewableHeight = textureComponent.viewableRect.bottom - textureComponent.viewableRect.top;

			D3DXVECTOR2 spriteCenter = D3DXVECTOR2(
				(float)(viewableWidth / 2 * transformComponent.scale),
				(float)(viewableHeight / 2 * transformComponent.scale)
			);

			D3DXVECTOR2 translate = D3DXVECTOR2(
				transformComponent.x,
				transformComponent.y
			);

			D3DXVECTOR2 scaling = D3DXVECTOR2(
				transformComponent.scale,
				transformComponent.scale
			);

			if (transformComponent.flipHorizontal)
			{
				scaling.x *= -1;
				spriteCenter.x -= (float)(viewableWidth * transformComponent.scale);
				translate.x += (float)(viewableWidth * transformComponent.scale);
			}

			if (transformComponent.flipVertical)
			{
				scaling.y *= -1;
				spriteCenter.y -= (float)(viewableHeight * transformComponent.scale);
				translate.y += (float)(viewableHeight * transformComponent.scale);
			}

			D3DXMATRIX matrix;
			D3DXMatrixTransformation2D(
				&matrix,                   // the matrix
				NULL,                      // keep origin at top left when scaling
				0.0f,                      // no scaling rotation
				&scaling,                  // scale amount
				&spriteCenter,             // rotation center
				transformComponent.angle,  // rotation angle
				&translate);               // X,Y location

			sprite->SetTransform(&matrix);
			sprite->Draw(
				textureComponent.texture,
				&textureComponent.viewableRect,
				NULL,
				NULL,
				textureComponent.filter
			);
		}

		this->graphics->spriteEnd();
	}

	void Render::releaseAll() {
		// Get all texture components
		std::vector<Component::Texture>* componentsPtr =
			this->manager->getComponents<Component::Texture>();

		// Release textures
		for (Component::Texture textureComponent : *componentsPtr)
		{
			SAFE_RELEASE(textureComponent.texture);
		}

		System::releaseAll();
	}

	void Render::resetAll() {
		// Get all texture components
		std::vector<Component::Texture>* componentsPtr =
			this->manager->getComponents<Component::Texture>();

		// Reload textures
		for (Component::Texture textureComponent : *componentsPtr)
		{
			if (!textureComponent.loadTexture(graphics, textureComponent.filePath.c_str()))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error reloading texture."));
			}
			textureComponent.visible = true;
		}

		System::resetAll();
	}

}