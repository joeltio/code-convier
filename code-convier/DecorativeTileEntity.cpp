#include "DecorativeTileEntity.h"

namespace Entity {
	ECS::EntityIdType DecorativeTile::create(ECS::Manager* manager, Graphics* graphics, float x, float y, char type) {
		ECS::EntityIdType entityId = manager->createEntity<DecorativeTile>();

		// add the transform component
		Component::Transform transformComponent = Component::Transform();
		transformComponent.x = x;
		transformComponent.y = y;
		transformComponent.scale = 2;
		manager->addComponent<Component::Transform>(entityId, transformComponent);

		// add the texture component
		Component::Texture textureComponent = Component::Texture();
		switch (type)
		{
		case(' '):
			if (!textureComponent.loadTexture(graphics, BACKGROUND_TILE_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading solid tile entity texture"));
			}
			break;
		case('*'):
			if (!textureComponent.loadTexture(graphics, JAIL_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading solid tile entity texture"));
			}
			break;
		case('$'):
			if (!textureComponent.loadTexture(graphics, DOOR_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading solid tile entity texture"));
			}
			break;
		default:
			break;
		}
		manager->addComponent<Component::Texture>(entityId, textureComponent);

		return entityId;
	}
}