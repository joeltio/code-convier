#pragma once

#include "StateComponent.h"

namespace Component {

template<typename NewStateType> void State::changeState() {
	Types::TypeId stateTypeId = Types::toTypeId<NewStateType>();

	this->state = stateTypeId;
}

}