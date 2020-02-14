#include "EnergyOrbEntity.h"

namespace Entity {
	ECS::EntityIdType EnergyOrb::create(ECS::Manager* manager, Graphics* graphics, float x, float y, int energy) {
		ECS::EntityIdType entityId = manager->createEntity<EnergyOrb>();

		// add the transform component
		Component::Transform transformComponent = Component::Transform();
		transformComponent.x = x;
		transformComponent.y = y;

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

		// add the health recover component
		Component::HealthRecover HPRegenComponent = Component::HealthRecover();
		HPRegenComponent.health = energy;

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
				Component::Health entityHP = manager->getEntityComponent<Component::Health>(id);
				Component::HealthRecover orbEnergy = manager->getEntityComponent<Component::HealthRecover>(entityId);

				entityHP.health += orbEnergy.health;

				manager->removeEntity<EnergyOrb>(entityId);
			}
		};

		manager->addComponent<Component::HealthRecover>(entityId, HPRegenComponent);
		manager->addComponent<Component::Transform>(entityId, transformComponent);
		manager->addComponent<Component::Texture>(entityId, textureComponent);
		manager->addComponent<Component::StaticCollidable>(entityId, collidable);

		return entityId;
	}
}