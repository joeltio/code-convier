#pragma once

#include <unordered_map>

#include "fsmConstants.h"
#include "typeUtil.h"
#include "System.h"
#include "Manager.h"
#include "Store.h"
#include "State.h"

namespace System {
	class FiniteState : public ECS::System {
		private:
			FSM::Store* store = NULL;
			std::unordered_map<Types::TypeId, FSM::State*> states = TYPE_STATE_MAP;

		public:
			void initialize(ECS::Manager* manager, Graphics* graphics, Input* input);
			void update(float frameTime);
			void render();
			void releaseAll();
	};
}
