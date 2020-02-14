#pragma once

#include <vector>
#include <forward_list>
#include <list>
#include <tuple>

#include "Entity.h"
#include "System.h"
#include "Manager.h"

#include "collisionConstants.h"
#include "CollisionStrategy.h"

#include "StaticCollidableComponent.h"
#include "CollidableComponent.h"
#include "StaticCollidableComponent.h"
#include "PhysicsComponent.h"

namespace System {

	class Collision : public ECS::System {
		private:
			// Prune values using the x-axis
			char pruneAxis = 0;

			// [[componentType, componentIndex, componentEntityId], ...]
			std::vector<std::tuple<Types::TypeId, size_t, float>>* sortedExtents = NULL;
			std::vector<CollisionUtil::CollisionStrategy*> strategies;
			// Searches for a strategy to use to check for collision between a and b
			bool colliding(Component::Collidable& a, Component::Collidable& b);
			// Tests for collision and updates a and b accordingly
			void handleCollision(Component::Collidable& a, Component::Collidable& b, float frameTime);
			void updateSortedExtents(
				std::unordered_map<Types::TypeId, std::vector<ECS::Component>*>& componentsPtrMap,
				std::unordered_map<Types::TypeId, ECS::RETRIEVER_PAIR>& retrieverMap,
				std::function<float(Types::TypeId, ECS::Component*)> extentRetriever
			);
			void insertNewExtent(
				std::tuple<Types::TypeId, size_t, float>& newExtent
			);

		public:
			void initialize(ECS::Manager* manager, Graphics* graphics, Input* input);
			void update(float frameTime);
			void releaseAll();
	};

}
