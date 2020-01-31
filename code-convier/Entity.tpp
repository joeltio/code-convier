#include "Entity.h"

namespace ECS {

// template is used here over passing TypeId as a variable so that toTypeId
// does not have to be used
template<typename T> bool Entity::isSameType() {
	return Types::isSameType(Types::toTypeId<T>(), this->entityTypeId);
}

}
