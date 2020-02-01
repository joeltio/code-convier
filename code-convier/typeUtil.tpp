#pragma once

#include "typeUtil.h"

namespace Types {

template<typename T> TypeId toTypeId() {
	return std::type_index(typeid(T));
}

}
