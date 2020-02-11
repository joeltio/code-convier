#pragma once

#include "typeUtil.h"
#include "Component.h"

namespace Component {
	// All derived components must not have any other fields so that
	// FiniteStateSystem can cast vector<Component> to vector<State> safely
	struct State : public ECS::Component {
		public:
			Types::TypeId state;

			template<typename NewStateType> void changeState();
	};
}

#include "StateComponent.tpp"
