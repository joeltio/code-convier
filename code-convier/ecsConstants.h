#pragma once

#include "System.h"

#include "FiniteStateSystem.h"
#include "PhysicsSystem.h"
#include "CollisionSystem.h"
#include "AnimationSystem.h"
#include "EnemyAISystem.h"
#include "RenderSystem.h"

// Systems to use
static ECS::System* ENABLED_SYSTEMS[] = {
	new System::FiniteState(),
	new System::Physics(),
	new System::Collision(),
	new System::Animation(),
	new System::EnemyAISystem(),
	new System::Render(),
};
