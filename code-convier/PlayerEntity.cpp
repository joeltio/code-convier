#include "PlayerEntity.h"

namespace Entity {
	ECS::EntityIdType Player::create(ECS::Manager* manager) {
		ECS::EntityIdType entityId = manager->createEntity<Player>();

		return entityId
	}
}