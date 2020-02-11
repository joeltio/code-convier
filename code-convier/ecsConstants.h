#pragma once

#include "System.h"

#include "FiniteStateSystem.h"
#include "PhysicsSystem.h"
#include "RenderSystem.h"

// Systems to use
static ECS::System* ENABLED_SYSTEMS[] = {
	new System::FiniteState(),
	new System::Physics(),
	new System::Render(),
};
