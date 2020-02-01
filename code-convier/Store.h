#pragma once

#include <forward_list>

#include "Action.h"
#include "Reducer.h"
#include "Manager.h"

namespace FSM {
	class Store {
		private:
			ECS::Manager* manager = NULL;
			std::forward_list<Reducer*> reducers;

		public:
			Store() {};
			~Store();
			Store(ECS::Manager* manager);
			void registerReducer(Reducer* reducer);
			void dispatchAction(Action &action);
	};
}
