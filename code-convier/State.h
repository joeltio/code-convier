#pragma once

#include "Manager.h"
#include "graphics.h"
#include "input.h"
#include "Action.h"

namespace FSM {
	class State {
		private:
			ECS::Manager* manager = NULL;
			Graphics* graphics = NULL;
			Input* input = NULL;

		public:
			virtual void initialize(ECS::Manager* manager, Graphics* graphics, Input* input);
			virtual Action update(float frameTime) = 0;
			virtual Action render() { return NoAction(); };
			virtual void enter() {};
			virtual void exit() {};
	};
}
