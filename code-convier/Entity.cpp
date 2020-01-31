#include "Entity.h"

namespace ECS {

EntityIdType Entity::createEntityId(EntityIdType previousId) {
	// Assuming that previousId is some number which can be incremented
	// Take note that previousId may also be NULL, but since NULL is 0, it can
	// still be incremented.
	return previousId + 1;
}

Entity::Entity() {
	this->id = NULL;
}

// entityTypeId is passed as an argument so that it is easier to manage
// entities in container types
Entity::Entity(EntityIdType id, Types::TypeId entityTypeId) {
	this->id = id;
	this->entityTypeId = entityTypeId;
}

Entity::~Entity() {}

}