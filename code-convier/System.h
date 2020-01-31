#pragma once

#include "Manager.h"
#include "graphics.h"
#include "input.h"

namespace ECS {

class System {
	protected:
		Manager* manager = NULL;
		Graphics* graphics = NULL;
		Input* input = NULL;

	public:
		System();
		virtual ~System();

		virtual void initialize(Manager* manager, Graphics* graphics, Input* input);

		virtual void update(float frameTime) {};

		virtual void render() {};

		virtual void releaseAll() {};

		virtual void resetAll() {};
};

}
