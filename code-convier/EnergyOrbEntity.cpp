#include "EnergyOrbEntity.h"

namespace Entity {
	ECS::EntityIdType EnergyOrb::create(ECS::Manager* manager, Graphics* graphics, float x, float y, int energy) {
		ECS::EntityIdType entityId = manager->createEntity<EnergyOrb>();

		// add the transform component
		Component::Transform transformComponent = Component::Transform();
		transformComponent.x = x;
		transformComponent.y = y;

		// add the physics component
		Component::Physics physicsComponent = Component::Physics();
		physicsComponent.acceleration[0] = 0;
		physicsComponent.acceleration[1] = 0;

		// add the texture component
		Component::Texture textureComponent = Component::Texture();
		switch (rand() % 4) {
		case(0):
			if (!textureComponent.loadTexture(graphics, XP_1_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading energy orb entity texture"));
			}
			break;
		case(1):
			if (!textureComponent.loadTexture(graphics, XP_2_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading energy orb entity texture"));
			}
			break;
		case(2):
			if (!textureComponent.loadTexture(graphics, XP_3_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading energy orb entity texture"));
			}
			break;
		case(3):
			if (!textureComponent.loadTexture(graphics, XP_4_IMAGE))
			{
				throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading energy orb entity texture"));
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

		collidable.onEnter = [entityId, energy](ECS::Manager* manager, ECS::EntityIdType id) {
			if (manager->getEntity(id)->isSameType<Player>())
			{
				Component::Health& entityHP = manager->getEntityComponent<Component::Health>(id);
				entityHP.storedHealth += energy;

				manager->removeEntity<EnergyOrb>(entityId);
			}
		};

		//add state component
		Component::EnergyOrbState orbStateComponent = Component::EnergyOrbState{
			entityId,
			true,
			Types::toTypeId<EnergyOrb>()
		};

		manager->addComponent<Component::Physics>(entityId, physicsComponent);
		manager->addComponent<Component::EnergyOrbState>(entityId, orbStateComponent);
		manager->addComponent<Component::Transform>(entityId, transformComponent);
		manager->addComponent<Component::Texture>(entityId, textureComponent);
		manager->addComponent<Component::StaticCollidable>(entityId, collidable);

		return entityId;
	}
}