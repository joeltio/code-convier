#pragma once

#include <forward_list>
#include <unordered_map>

#include "typeUtil.h"
#include "State.h"
#include "Action.h"
#include "Reducer.h"
#include "Manager.h"

namespace FSM {
	class Store {
		private:
			ECS::Manager* manager = NULL;
			std::unordered_map<Types::TypeId, State*> states;
			std::forward_list<Reducer*> reducers;

		public:
			Store() {};
			~Store();
			Store(ECS::Manager* manager, std::unordered_map<Types::TypeId, State*> states);
			void registerReducer(Reducer* reducer);
			void dispatchAction(Action &action);
	};
}
