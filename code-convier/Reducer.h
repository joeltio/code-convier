#pragma once

#include <unordered_map>

#include "typeUtil.h"
#include "Manager.h"
#include "State.h"
#include "Action.h"

namespace FSM {
	class Reducer {
		protected:
			static void changeState();
		public:
			virtual bool acceptsAction(Action &action) = 0;
			virtual void reduce(
				ECS::Manager* manager,
				std::unordered_map<Types::TypeId, State*> states,
				FSM::Action action
			) = 0;
	};
}
