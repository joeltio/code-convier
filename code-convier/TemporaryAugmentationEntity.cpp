#include "TemporaryAugmentationEntity.h"

namespace Entity {

	ECS::EntityIdType TemporaryAugmentation::create(ECS::Manager* manager, Graphics* graphics) {

		ECS::EntityIdType temporaryAugmentationId = manager->createEntity<TemporaryAugmentation>();

		Component::Texture textureComponent = Component::Texture();
		if (!textureComponent.loadTexture(graphics, TEMPORARY_AUGMENTATION_IMAGE))
		{
			throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading Temporary Augmentation entity texture"));
		}
		textureComponent.zIndex = 3;

		manager->addComponent<Component::Texture>(temporaryAugmentationId, textureComponent);

		Component::Transform transformComponent = Component::Transform();
		transformComponent.x = 0;
		transformComponent.y = 0;

		manager->addComponent<Component::Transform>(temporaryAugmentationId, transformComponent);

		return temporaryAugmentationId;
	}
}

