#include "CollisionSystem.h"

namespace System {

	bool Collision::colliding(Component::Collidable& a, Component::Collidable& b) {
		for (CollisionUtil::CollisionStrategy* strategy : this->strategies)
		{
			// Look for a strategy to handle this collision
			if (strategy->isUseable(a.collisionType, b.collisionType))
			{
				return strategy->isColliding(a, b);
			}
		}

		// No strategy found, throw an error
		throw(GameError(gameErrorNS::FATAL_ERROR, "Unable to find collision strategy to handle collision."));
	}

	void Collision::handleCollision(Component::Collidable& a, Component::Collidable& b, float frameTime) {
		// Check if the entities are already colliding with each other
		bool wasColliding =
			a.collidingWith.find(b.entityId) != b.collidingWith.end();
		bool isColliding = this->colliding(a, b);

		// Update the "isColliding" and call functions
		if (!wasColliding && isColliding)
		{
			a.collidingWith.insert(b.entityId);
			b.collidingWith.insert(a.entityId);
			a.onEnter(this->manager, b.entityId);
			b.onEnter(this->manager, a.entityId);
		}
		else if (wasColliding && isColliding)
		{
			a.onStay(this->manager, b.entityId, frameTime);
			b.onStay(this->manager, a.entityId, frameTime);
		}
		else if (wasColliding && !isColliding)
		{
			a.collidingWith.erase(b.entityId);
			b.collidingWith.erase(a.entityId);
			a.onExit(this->manager, b.entityId);
			b.onExit(this->manager, a.entityId);
		}

	}

	void Collision::updateSortedExtents(
		std::vector<Component::Collidable>* collidables,
		std::vector<Component::StaticCollidable>* staticCollidables
	) {
		// Keep track of the new pairs to be inserted and removed
		std::forward_list<std::tuple<bool, size_t, float>> toBeInserted;

		// Keep track of highest index of components
		int maxCollidableIndex = -1;
		int maxStaticIndex = -1;

		// Find the new pairs to be inserted and delete removed components
		for (auto iterator = this->sortedExtents.cbegin(); iterator != this->sortedExtents.cend(); iterator++)
		{
			auto extentTriple = *iterator;
			bool isStatic = std::get<0>(extentTriple);
			size_t componentIndex = std::get<1>(extentTriple);
			float storedExtent = std::get<2>(extentTriple);

			// Check if the component had been deleted
			if (isStatic)
			{
				// Update max component index
				if (componentIndex > maxStaticIndex)
				{
					maxStaticIndex = componentIndex;
				}

				// Get static collidable
				Component::StaticCollidable& collidable = staticCollidables->at(componentIndex);
				// Check if the component has been deleted (inactive)
				if (!collidable.isActive)
				{
					this->sortedExtents.erase(iterator--);
				}

				// Check if the component's extents have changed
				float currentExtent = collidable.getMinExtent(this->pruneAxis);
				if (currentExtent != storedExtent)
				{
					this->sortedExtents.erase(iterator--);
					std::get<2>(extentTriple) = currentExtent;
					toBeInserted.push_front(extentTriple);
				}
			}
			else
			{
				// Update max component index
				if (componentIndex > maxCollidableIndex)
				{
					maxCollidableIndex = componentIndex;
				}

				// Get collidable
				Component::Collidable& collidable = collidables->at(componentIndex);
				// Check if the component has been deleted (inactive)
				if (!collidable.isActive)
				{
					this->sortedExtents.erase(iterator--);
				}

				// Check if the component's extents have changed
				float currentExtent = collidable.getMinExtent(this->pruneAxis);
				if (currentExtent != storedExtent)
				{
					this->sortedExtents.erase(iterator--);
					std::get<2>(extentTriple) = currentExtent;
					toBeInserted.push_front(extentTriple);
				}
			}
		}

		// Find any completely new components
		if (maxCollidableIndex < collidables->size())
		{
			for (size_t i = maxCollidableIndex + 1; i < collidables->size(); i++)
			{
				toBeInserted.push_front(std::tuple(
					false,
					i,
					collidables->at(maxCollidableIndex).entityId
				));
			}
		}

		if (maxStaticIndex < staticCollidables->size())
		{
			for (size_t i = maxStaticIndex + 1; i < staticCollidables->size(); i++)
			{
				toBeInserted.push_front(std::tuple(
					true,
					i,
					staticCollidables->at(maxCollidableIndex).entityId
				));
			}
		}

		// Insert new items
		for (auto extentTriple : toBeInserted)
		{
			this->insertNewExtent(collidables, staticCollidables, extentTriple);
		}
	}

	void Collision::insertNewExtent(
		std::vector<Component::Collidable>* collidables,
		std::vector<Component::StaticCollidable>* staticCollidables,
		std::tuple<bool, size_t, float>& newExtent
	) {
		float newMinX = std::get<2>(newExtent);

		auto iterator = this->sortedExtents.cbegin();
		for (iterator = this->sortedExtents.cbegin(); iterator != this->sortedExtents.cend(); iterator++)
		{
			auto extentTriple = *iterator;
			float currentMinX = std::get<2>(extentTriple);
			if (currentMinX > newMinX)
			{
				break;
			}
		}

		this->sortedExtents.insert(iterator, newExtent);
	}

	void Collision::initialize(ECS::Manager* manager, Graphics* graphics, Input* input) {
		System::initialize(manager, graphics, input);
		// Add the collision strategies
		for (CollisionUtil::CollisionStrategy* strategy : COLLISION_STRATEGIES)
		{
			this->strategies.push_back(strategy);
		}
	}

	void Collision::update(float frameTime) {
		// Get all collidable components
		std::vector<Component::Collidable>* collidablesPtr =
			this->manager->getComponents<Component::Collidable>();
		std::vector<Component::StaticCollidable>* staticCollidablesPtr =
			this->manager->getComponents<Component::StaticCollidable>();

		// Update sorted extents
		this->updateSortedExtents(collidablesPtr, staticCollidablesPtr);

		for (auto iterator = this->sortedExtents.cbegin(); iterator != this->sortedExtents.cend(); iterator++)
		{
			auto extentTriple = *iterator;
			float maxExtent = std::get<2>(extentTriple);

			// Iterate through subsequent elements
			auto subItr = iterator;
			subItr++;
			for (subItr = subItr; subItr != this->sortedExtents.cend(); subItr++)
			{
				auto subExtentTriple = *subItr;
				float subMinExtent = std::get<2>(subExtentTriple);

				if (subMinExtent < maxExtent)
				{
					// Following collidables will also not be colliding
					break;
				}

				// If both are not static collidables
				if (!(std::get<0>(extentTriple) && std::get<0>(subExtentTriple)))
				{
					Component::Collidable* a = NULL;
					Component::Collidable* b = NULL;
					if (std::get<0>(extentTriple))
					{
						a = &staticCollidablesPtr->at(std::get<1>(extentTriple));
						b = &collidablesPtr->at(std::get<1>(subExtentTriple));
					}
					else if (std::get<0>(subExtentTriple))
					{
						a = &collidablesPtr->at(std::get<1>(extentTriple));
						b = &staticCollidablesPtr->at(std::get<1>(subExtentTriple));
					}
					else
					{
						a = &collidablesPtr->at(std::get<1>(extentTriple));
						b = &collidablesPtr->at(std::get<1>(subExtentTriple));
					}

					// Check for collision
					this->handleCollision(*a, *b, frameTime);
				}
			}
		}
	}

	void Collision::releaseAll() {
		// Delete all the strategies
		for (CollisionUtil::CollisionStrategy* strategy : this->strategies)
		{
			SAFE_DELETE(strategy);
		}
	}
}