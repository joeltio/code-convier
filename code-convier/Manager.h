#pragma once

#include <utility>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <typeindex>

#include "constants.h"
#include "typeUtil.h"
#include "Entity.h"
#include "Component.h"

namespace ECS {

class Manager {
	private:
		// EntityId -> Entity*
		std::unordered_map<EntityIdType, Entity*> entities;
		// EntityType -> unordered_set<EntityId>*
		std::unordered_map<Types::TypeId, std::unordered_set<EntityIdType>*> entityFamilies;
		// Component -> vector<Component>*
		std::unordered_map<Types::TypeId, void*> components;
		// EntityId -> ComponentType -> vector index
		std::unordered_map<EntityIdType, std::unordered_map<Types::TypeId, int>*> entityComponents;
		// Map of queues of components which have been deleted
		// Component -> queue<Component>*
		std::unordered_map<Types::TypeId, std::queue<int>*> deletedComponents;
		EntityIdType lastCreatedEntityId = NULL;

	public:
		Manager() {};
		~Manager() { this->releaseAll(); };

		// Managing ECS
		template<typename EntityType> EntityIdType createEntity();

		Entity* getEntity(EntityIdType id);
		std::unordered_set<EntityIdType>* getEntities(Types::TypeId entityType);
		template<typename ComponentType> std::vector<ComponentType>* getComponents();
		std::vector<Component>* getComponents(Types::TypeId componentTypeId);
		template<typename ComponentType> ComponentType& getEntityComponent(EntityIdType id);
		template<typename EntityType> std::unordered_set<EntityIdType>* getEntities();
		template<typename ComponentType> bool entityHasComponent(EntityIdType id);

		template<typename ComponentType> void addComponent(EntityIdType id, ComponentType component);

		// Removes entity and its components immediately
		template<typename EntityType> void removeEntity(EntityIdType id);
		// Removes entity and its components immediately
		void removeEntity(EntityIdType id, Types::TypeId entityType);

		// Memory clean up
		void releaseAll();
};

}

#include "Manager.tpp"
