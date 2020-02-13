#include "SolidTileEntity.h"

namespace Entity {
	ECS::EntityIdType SolidTile::create(ECS::Manager* manager, Graphics* graphics, float x, float y, char type) {
		ECS::EntityIdType entityId = manager->createEntity<SolidTile>();

		// add the transform component
		Component::Transform transformComponent = Component::Transform();
		transformComponent.x = x;
		transformComponent.y = y;
		transformComponent.scale = 2;
		manager->addComponent<Component::Transform>(entityId, transformComponent);

		// add the staticCollidable component
		/*Component::StaticCollidable collidable = Component::StaticCollidable();
		collidable.onEnter = [entityId](ECS::Manager* manager, ECS::EntityIdType id) {
			if (id )
			{

			}
		};*/

		// add the texture component
		Component::Texture textureComponent = Component::Texture();
		switch (type)
		{
		case('.'):
			if (!textureComponent.loadTexture(graphics, NORMAL_WALL_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading solid tile entity texture"));
			}
			break;
		case('-'):
			if (!textureComponent.loadTexture(graphics, BOTTOM_WALL_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading solid tile entity texture"));
			}
			break;
		case('_'):
			if (!textureComponent.loadTexture(graphics, TOP_WALL_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading solid tile entity texture"));
			}
			break;
		case('/'):
			if (!textureComponent.loadTexture(graphics, TOP_LEFT_CORNER_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading solid tile entity texture"));
			}
			break;
		case('\\'):
			if (!textureComponent.loadTexture(graphics, TOP_RIGHT_CORNER_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading solid tile entity texture"));
			}
			break;
		case('('):
			if (!textureComponent.loadTexture(graphics, LEFT_WALL_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading solid tile entity texture"));
			}
			break;
		case(')'):
			if (!textureComponent.loadTexture(graphics, RIGHT_WALL_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading solid tile entity texture"));
			}
			break;
		case('<'):
			if (!textureComponent.loadTexture(graphics, BOTTOM_LEFT_CORNER_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading solid tile entity texture"));
			}
			break;
		case('>'):
			if (!textureComponent.loadTexture(graphics, BOTTOM_RIGHT_CORNER_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading solid tile entity texture"));
			}
			break;
		case('{'):
			if (!textureComponent.loadTexture(graphics, PLATFORM_START_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading solid tile entity texture"));
			}
			break;
		case('}'):
			if (!textureComponent.loadTexture(graphics, PLATFORM_END_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading solid tile entity texture"));
			}
			break;
		case('1'):
			if (!textureComponent.loadTexture(graphics, PLATFORM1_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading solid tile entity texture"));
			}
			break;
		case('2'):
			if (!textureComponent.loadTexture(graphics, PLATFORM2_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading solid tile entity texture"));
			}
			break;
		case('3'):
			if (!textureComponent.loadTexture(graphics, PLATFORM3_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading solid tile entity texture"));
			}
			break;
		case('4'):
			if (!textureComponent.loadTexture(graphics, PLATFORM4_IMAGE))
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