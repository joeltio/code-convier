#pragma once

#include "Manager.h"
#include "Action.h"

namespace FSM {
	class Reducer {
		public:
			virtual bool acceptsAction(Action &action) = 0;
			virtual void reduce(ECS::Manager* manager, FSM::Action action) = 0;
	};
}
