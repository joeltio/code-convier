#include "SolidTileEntity.h"

namespace Entity {
	ECS::EntityIdType SolidTile::create(ECS::Manager* manager, Graphics* graphics, float x, float y, char type) {
		ECS::EntityIdType entityId = manager->createEntity<SolidTile>();

		// add the transform component
		Component::Transform transformComponent = Component::Transform();
		transformComponent.x = x;
		transformComponent.y = y;
		transformComponent.scale = 2;

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

		// add the staticCollidable component
		Component::StaticCollidable collidable = Component::StaticCollidable(CollisionUtil::CollisionType::AABB);
		float width = textureComponent.totalWidth * transformComponent.scale;
		float height = textureComponent.totalHeight * transformComponent.scale;
		collidable.corners.push_back(D3DXVECTOR2(x, y));
		collidable.corners.push_back(D3DXVECTOR2(x + width, y));
		collidable.corners.push_back(D3DXVECTOR2(x + width, y + height));
		collidable.corners.push_back(D3DXVECTOR2(x, y + height));

		collidable.onEnter = [entityId](ECS::Manager* manager, ECS::EntityIdType id) {
			if (manager->getEntity(id)->isSameType<Player>())
			{
				Component::Jumping& playerJump = manager->getEntityComponent<Component::Jumping>(id);
				playerJump.isJumping = false;
			}
		};

		collidable.onStay = [entityId](ECS::Manager* manager, ECS::EntityIdType id, float frameTime) {
			if (manager->getEntity(id)->isSameType<Player>())
			{
				Component::Transform& entityPos = manager->getEntityComponent<Component::Transform>(id);
				Component::Collidable& entityCol = manager->getEntityComponent<Component::Collidable>(id);
				Component::Physics& entityPhy = manager->getEntityComponent<Component::Physics>(id);
				Component::StaticCollidable tileCol = manager->getEntityComponent<Component::StaticCollidable>(entityId);

				entityPhy.velocity[1] = 0;

				float entityWidth = entityCol.corners[1][0] - entityCol.corners[0][0];
				float entityHeight = entityCol.corners[2][1] - entityCol.corners[0][1];

				float xDiff = tileCol.getCenter()[0] - entityCol.getCenter()[0];
				float yDiff = tileCol.getCenter()[1] - entityCol.getCenter()[1];
				if (abs(yDiff) > abs(xDiff))
				{
					if (yDiff > 0)
					{
						entityPos.y = tileCol.corners[0][1] - entityHeight - 1;
					}
					else if (yDiff < 0)
					{
						entityPos.y = tileCol.corners[3][1] + 1;
					}
				}
				else if (abs(xDiff) > abs(yDiff))
				{
					if (xDiff > 0)
					{
						entityPos.x = tileCol.corners[0][0] - entityWidth - 1;
					}
					else if (xDiff < 0)
					{
						entityPos.x = tileCol.corners[1][0] + 1;
					}
				}

				std::vector<D3DXVECTOR2> corners = {
					{(float)entityPos.x, (float)entityPos.y},
					{(float)entityPos.x + entityWidth, (float)entityPos.y},
					{(float)entityPos.x + entityWidth, (float)entityPos.y + entityHeight},
					{(float)entityPos.x, (float)entityPos.y + entityHeight}
				};
				
				entityCol.corners = corners;
			}
		};

		manager->addComponent<Component::Transform>(entityId, transformComponent);
		manager->addComponent<Component::Texture>(entityId, textureComponent);
		manager->addComponent<Component::StaticCollidable>(entityId, collidable);

		return entityId;
	}
}