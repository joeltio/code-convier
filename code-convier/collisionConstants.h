#pragma once

#include "CollisionStrategy.h"

#include "AABBAABBCollisionStrategy.h"
#include "AABBCircleCollisionStrategy.h"
#include "AABBOBBCollisionStrategy.h"
#include "CircleCircleCollisionStrategy.h"
#include "CircleLineCollisionStrategy.h"
#include "CircleOBBCollisionStrategy.h"
#include "LineLineCollisionStrategy.h"
#include "OBBOBBCollisionStrategy.h"
#include "SquareLineCollisionStrategy.h"

// Collision strategies available
static CollisionUtil::CollisionStrategy* COLLISION_STRATEGIES[] = {
	new CollisionUtil::AABBAABBCollisionStrategy(),
	new CollisionUtil::AABBCircleCollisionStrategy(),
	new CollisionUtil::AABBOBBCollisionStrategy(),
	new CollisionUtil::CircleCircleCollisionStrategy(),
	new CollisionUtil::CircleLineCollisionStrategy(),
	new CollisionUtil::CircleOBBCollisionStrategy(),
	new CollisionUtil::LineLineCollisionStrategy(),
	new CollisionUtil::OBBOBBCollisionStrategy(),
	new CollisionUtil::SquareLineCollisionStrategy()
};
