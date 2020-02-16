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
			a.collidingWith.find(b.entityId) != a.collidingWith.end();
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
		std::unordered_map<Types::TypeId, std::vector<ECS::Component>*>& componentsPtrMap,
		std::unordered_map<Types::TypeId, ECS::RETRIEVER_PAIR>& retrieverMap,
		std::function<float(Types::TypeId, ECS::Component*)> extentRetriever
	) {
		// Keep track of the new triples to be inserted and removed
		std::forward_list<std::tuple<Types::TypeId, size_t, float>> toBeInserted;
		// Keep track of the triples to be reordered
		std::forward_list<std::tuple<Types::TypeId, size_t, float>> toBeMoved;

		// Determine the size of the components vectors
		std::unordered_map<Types::TypeId, size_t> compSize;
		for (auto retrieverMapPair : retrieverMap)
		{
			// Initialize with 0s
			compSize.insert(std::make_pair(retrieverMapPair.first, 0));
		}

		// Find the new pairs to be inserted and delete removed components
		size_t i = 0;
		while (i < this->sortedExtents->size())
		{
			auto& extentTriple = this->sortedExtents->at(i);
			Types::TypeId type = std::get<0>(extentTriple);
			size_t componentIndex = std::get<1>(extentTriple);
			float& storedExtent = std::get<2>(extentTriple);

			// Update max component index
			size_t& maxSize = compSize.at(type);
			if (componentIndex >= maxSize)
			{
				maxSize = componentIndex + 1;
			}

			// Retrieve component
			auto& retrieverPair = retrieverMap.at(type);
			ECS::Component* componentPtr = retrieverPair.second(componentsPtrMap.at(type), componentIndex);

			// Check if the component has been deleted (inactive)
			if (!componentPtr->isActive)
			{
				this->sortedExtents->erase(this->sortedExtents->begin() + i);
				i--;
			}

			// Check if component's contents have changed
			float currentExtent = extentRetriever(type, componentPtr);
			if (currentExtent != storedExtent)
			{
				storedExtent = currentExtent;
				toBeInserted.push_front(extentTriple);
				this->sortedExtents->erase(this->sortedExtents->begin() + i);
				i--;
			}

			i++;
		}

		// Find any completely new components
		for (auto retrieverMapPair : retrieverMap)
		{
			Types::TypeId type = retrieverMapPair.first;
			ECS::RETRIEVER_PAIR& retrieverPair = retrieverMapPair.second;
			if (compSize.at(type) < retrieverPair.first)
			{
				for (size_t i = compSize.at(type); i < retrieverPair.first; i++)
				{
					ECS::Component* componentPtr = retrieverPair.second(componentsPtrMap.at(type), i);
					toBeInserted.push_front(std::tuple(
						type,
						i,
						extentRetriever(type, componentPtr)
					));
				}
			}
		}

		// Insert new items
		for (auto extentTriple : toBeInserted)
		{
			this->insertNewExtent(extentTriple);
		}
	}

	void Collision::insertNewExtent(
		std::tuple<Types::TypeId, size_t, float>& newExtent
	) {
		float newMinX = std::get<2>(newExtent);

		size_t i;
		for (i = 0; i < this->sortedExtents->size(); i++)
		{
			auto& extentTriple = this->sortedExtents->at(i);
			float currentMinX = std::get<2>(extentTriple);
			if (currentMinX > newMinX)
			{
				break;
			}
		}

		this->sortedExtents->insert(this->sortedExtents->begin() + i, newExtent);
	}

	void Collision::initialize(ECS::Manager* manager, Graphics* graphics, Input* input) {
		System::initialize(manager, graphics, input);
		// Add the collision strategies
		for (CollisionUtil::CollisionStrategy* strategy : COLLISION_STRATEGIES)
		{
			this->strategies.push_back(strategy);
		}

		this->sortedExtents = new std::vector<std::tuple<Types::TypeId, size_t, float>>();
		// Reserve large amount of space for sortedExtents
		this->sortedExtents->reserve(10000);
	}

	void Collision::update(float frameTime) {
		// Keep track of componentsPtrs
		std::unordered_map<Types::TypeId, std::vector<ECS::Component>*> componentsPtrMap = {
			{Types::toTypeId<Component::Collidable>(),
				this->manager->getComponents(Types::toTypeId<Component::Collidable>())},
			{Types::toTypeId<Component::StaticCollidable>(),
				this->manager->getComponents(Types::toTypeId<Component::StaticCollidable>())},
			{Types::toTypeId<Component::LineOfSight>(),
				this->manager->getComponents(Types::toTypeId<Component::LineOfSight>())},
			{Types::toTypeId<Component::HurtBox>(),
				this->manager->getComponents(Types::toTypeId<Component::HurtBox>())}
		};

		// Keep track of retrievers
		std::unordered_map<Types::TypeId, ECS::RETRIEVER_PAIR> retrieverMap = {
			{Types::toTypeId<Component::Collidable>(),
				this->manager->getComponentRetriever(Types::toTypeId<Component::Collidable>())},
			{Types::toTypeId<Component::StaticCollidable>(),
				this->manager->getComponentRetriever(Types::toTypeId<Component::StaticCollidable>())},
			{Types::toTypeId<Component::LineOfSight>(),
				this->manager->getComponentRetriever(Types::toTypeId<Component::LineOfSight>())},
			{Types::toTypeId<Component::HurtBox>(),
				this->manager->getComponentRetriever(Types::toTypeId<Component::HurtBox>())}
		};

		// Update sorted extents
		char pruneAxis = this->pruneAxis;
		this->updateSortedExtents(
			componentsPtrMap,
			retrieverMap,
			[pruneAxis](Types::TypeId type, ECS::Component* component) {
				if (Types::isSameType(Types::toTypeId<Component::Collidable>(), type))
				{
					return ((Component::Collidable*) component)->getMinExtent(pruneAxis);
				}
				else if (Types::isSameType(Types::toTypeId<Component::StaticCollidable>(), type))
				{
					return ((Component::StaticCollidable*) component)->getMinExtent(pruneAxis);
				}
				else if (Types::isSameType(Types::toTypeId<Component::LineOfSight>(), type))
				{
					return ((Component::LineOfSight*) component)->getMinExtent(pruneAxis);
				}
				else if (Types::isSameType(Types::toTypeId<Component::HurtBox>(), type))
				{
					return ((Component::HurtBox*) component)->getMinExtent(pruneAxis);
				}

				throw new std::exception("Unknown component type when retrieving collidable extent.");
			}
		);

		for (size_t i = 0; i < this->sortedExtents->size(); i++)
		{
			auto& extentTriple = this->sortedExtents->at(i);
			Types::TypeId type = std::get<0>(extentTriple);
			size_t componentIndex = std::get<1>(extentTriple);
			// Get max extent
			Component::Collidable* component =
				(Component::Collidable*) retrieverMap.at(type).second(componentsPtrMap.at(type), componentIndex);
			float maxExtent = component->getMaxExtent(this->pruneAxis);

			bool isStatic = Types::isSameType(type, Types::toTypeId<Component::StaticCollidable>());

			// Iterate through subsequent elements
			for (size_t j = i+1; j < this->sortedExtents->size(); j++)
			{
				auto& subExtentTriple = this->sortedExtents->at(j);
				Types::TypeId& subType = std::get<0>(subExtentTriple);
				size_t subComponentIndex = std::get<1>(subExtentTriple);
				float subMinExtent = std::get<2>(subExtentTriple);

				if (maxExtent <= subMinExtent)
				{
					// Following collidables will also not be colliding
					break;
				}

				// Ignore if both are static collidables
				if (isStatic && Types::isSameType(type, subType))
				{
					continue;
				}

				std::vector<ECS::Component>* aComponentsPtr = componentsPtrMap.at(type);
				std::vector<ECS::Component>* bComponentsPtr = componentsPtrMap.at(subType);
				ECS::RETRIEVER_PAIR aRetrieverPair = retrieverMap.at(type);
				ECS::RETRIEVER_PAIR bRetrieverPair = retrieverMap.at(subType);

				Component::Collidable* a = (Component::Collidable*) aRetrieverPair.second(aComponentsPtr, componentIndex);
				Component::Collidable* b = (Component::Collidable*) bRetrieverPair.second(bComponentsPtr, subComponentIndex);

				this->handleCollision(*a, *b, frameTime);
			}
		}
	}

	void Collision::releaseAll() {
		// Delete all the strategies
		for (CollisionUtil::CollisionStrategy* strategy : this->strategies)
		{
			SAFE_DELETE(strategy);
		}

		// Delete sortedExtents
		SAFE_DELETE(this->sortedExtents);
	}
}
