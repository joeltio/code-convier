#pragma once

namespace ECS {
namespace Types {

template<typename T> TypeId toTypeId() {
	return std::type_index(typeid(T));
}

}
}
