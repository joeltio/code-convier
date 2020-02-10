#pragma once

#include "Manager.h"
#include "Store.h"
#include "graphics.h"
#include "input.h"

namespace FSM {
	class State {
		private:
			ECS::Manager* manager = NULL;
			Graphics* graphics = NULL;
			Input* input = NULL;
			Store* store = NULL;

		public:
			virtual void initialize(ECS::Manager* manager, Graphics* graphics, Input* input, Store* store);
			virtual void update(float frameTime) = 0;
			virtual void render() {};
			virtual void enter() {};
			virtual void exit() {};
	};
}
