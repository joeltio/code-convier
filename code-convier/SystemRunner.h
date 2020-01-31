#pragma once

#include <vector>
#include "manager.h"
#include "system.h"
#include "graphics.h"

namespace ECS {

class SystemRunner {
	private:
		std::vector<System*> systems;
		Graphics* graphics;

	public:
		SystemRunner() {};
		~SystemRunner() {};

		std::vector<System*> getSystems() { return this->systems; };
		void registerSystem(System* system);

		void initialize(Manager* manager, Graphics* graphics, Input* input);
		void update(float frameTime);
		void render();
		void releaseAll();
		void resetAll();
};

}
