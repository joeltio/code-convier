#pragma once

#include "CollisionStrategy.h"

#include "AABBAABBCollisionStrategy.h"
#include "AABBCircleCollisionStrategy.h"
#include "AABBOBBCollisionStrategy.h"
#include "CircleCircleCollisionStrategy.h"
#include "CircleOBBCollisionStrategy.h"
#include "OBBOBBCollisionStrategy.h"

// Collision strategies available
static CollisionUtil::CollisionStrategy* COLLISION_STRATEGIES[] = {
	new CollisionUtil::AABBAABBCollisionStrategy(),
	new CollisionUtil::AABBCircleCollisionStrategy(),
	new CollisionUtil::AABBOBBCollisionStrategy(),
	new CollisionUtil::CircleCircleCollisionStrategy(),
	new CollisionUtil::CircleOBBCollisionStrategy(),
	new CollisionUtil::OBBOBBCollisionStrategy()
};
