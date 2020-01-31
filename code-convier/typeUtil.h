#pragma once

#include <typeindex>

namespace ECS {
namespace Types {

typedef std::type_index TypeId;
template<typename T> TypeId toTypeId();
bool isSameType(TypeId a, TypeId b);
const TypeId NothingTypeId = toTypeId<void>();

}
}

#include "typeUtil.tpp"
