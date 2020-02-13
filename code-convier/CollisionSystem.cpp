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

	void Collision::initialize(ECS::Manager* manager, Graphics* graphics, Input* input) {
		System::initialize(manager, graphics, input);
		// Add the collision strategies
		this->strategies.push_back(new CollisionUtil::AABBAABBCollisionStrategy());
		this->strategies.push_back(new CollisionUtil::AABBCircleCollisionStrategy());
		this->strategies.push_back(new CollisionUtil::AABBOBBCollisionStrategy());
		this->strategies.push_back(new CollisionUtil::CircleCircleCollisionStrategy());
		this->strategies.push_back(new CollisionUtil::CircleOBBCollisionStrategy());
		this->strategies.push_back(new CollisionUtil::OBBOBBCollisionStrategy());
	}

	void Collision::update(float frameTime) {
		// Get all animatable components
		std::vector<Component::Collidable>* componentsPtr =
			this->manager->getComponents<Component::Collidable>();
		std::vector<Component::StaticCollidable>* staticCollidablesPtr =
			this->manager->getComponents<Component::StaticCollidable>();

		// Check collidables against collidables
		for (std::size_t i = 0; i < componentsPtr->size(); i++)
		{
			for (std::size_t j = i + 1; j < componentsPtr->size(); j++)
			{
				// Source collidable object
				Component::Collidable& source = componentsPtr->at(i);
				Component::Collidable& target = componentsPtr->at(j);

				this->handleCollision(source, target, frameTime);
			}
		}

		for (std::size_t i = 0; i < componentsPtr->size(); i++)
		{
			for (std::size_t j = 0; j < staticCollidablesPtr->size(); j++)
			{
				// Source collidable object
				Component::Collidable& source = componentsPtr->at(i);
				Component::Collidable& target = staticCollidablesPtr->at(j);

				this->handleCollision(source, target, frameTime);
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