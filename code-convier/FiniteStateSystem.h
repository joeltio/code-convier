#pragma once

#include <unordered_map>

#include "typeUtil.h"
#include "System.h"
#include "Store.h"
#include "State.h"

namespace System {
	class FiniteState : public ECS::System {
		private:
			FSM::Store store;
			std::unordered_map<ECS::Types::TypeId, FSM::State> states;

		public:
			void update(float frameTime);
	};
}
