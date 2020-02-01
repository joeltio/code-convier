#include "typeUtil.h"

namespace Types {

bool isSameType(TypeId a, TypeId b) {
	// type_index can be compared directly with ==
	return a == b;
}

}