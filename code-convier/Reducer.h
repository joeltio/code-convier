#pragma once

#include <unordered_map>

#include "typeUtil.h"
#include "Manager.h"
#include "State.h"
#include "Action.h"
#include "StateComponent.h"

namespace FSM {
	class Reducer {
		protected:
			template<typename NewStateType> static void changeState(
				std::unordered_map<Types::TypeId, State*>& states,
				Component::State& stateComponent
			);

		public:
			virtual bool acceptsAction(Action &action) = 0;
			virtual void reduce(
				ECS::Manager* manager,
				std::unordered_map<Types::TypeId, State*> states,
				FSM::Action action
			) = 0;
	};
}

#include "Reducer.tpp"
