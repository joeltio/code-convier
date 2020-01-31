#include "typeUtil.h"

namespace ECS {
namespace Types {

bool isSameType(TypeId a, TypeId b) {
	// type_index can be compared directly with ==
	return a == b;
}

}
}