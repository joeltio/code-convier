#pragma once

#include "typeUtil.h"
#include "Component.h"

namespace Component {
	struct State : public ECS::Component {
		Types::TypeId state;

		template<typename NewStateType> void changeState();
	};
}

#include "StateComponent.tpp"
