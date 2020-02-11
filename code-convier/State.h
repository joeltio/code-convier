#pragma once

#include "Manager.h"
#include "graphics.h"
#include "input.h"
#include "Action.h"
#include "StateComponent.h"

namespace FSM {
	class State {
		protected:
			ECS::Manager* manager = NULL;
			Graphics* graphics = NULL;
			Input* input = NULL;

		public:
			virtual void initialize(ECS::Manager* manager, Graphics* graphics, Input* input);
			virtual Action update(float frameTime, Component::State state) = 0;
			virtual Action render(Component::State state) { return NoAction(); };
			virtual void enter(Component::State state) {};
			virtual void exit(Component::State state) {};
	};
}
