#include "Manager.h"

namespace ECS {

Entity* Manager::getEntity(EntityIdType id) {
	return this->entities.at(id);
}

std::unordered_set<EntityIdType>* Manager::getEntities(Types::TypeId entityType) {
	if (this->entityFamilies.find(entityType) == this->entityFamilies.end())
	{
		// Add an empty set with the entityType if it does not exist
		std::unordered_set<EntityIdType>* emptySet = new std::unordered_set<EntityIdType>();
		std::pair<Types::TypeId, std::unordered_set<EntityIdType>*> emptyRecord
			(entityType, emptySet);
		this->entityFamilies.insert(emptyRecord);
	}

	return this->entityFamilies.at(entityType);
}

std::vector<Component>* Manager::getComponents(Types::TypeId componentTypeId) {
	if (this->components.find(componentTypeId) == this->components.end())
	{
		// Add an empty vector with the componentType if it does not exist
		std::vector<Component>* componentVector = new std::vector<Component>();
		std::pair<Types::TypeId, std::vector<Component>*> emptyRecord
			(componentTypeId, componentVector);
		this->components.insert(emptyRecord);
	}

	std::vector<Component>* componentVectorPtr = (std::vector<Component>*) this->components.at(componentTypeId);
	return componentVectorPtr;
}

void Manager::removeEntity(EntityIdType id, Types::TypeId entityTypeId) {
	// Remove the entity's components
	std::unordered_map<Types::TypeId, int>* componentMap = this->entityComponents.at(id);
	for (std::pair<Types::TypeId, int> componentPair : *componentMap)
	{
		Types::TypeId componentType = componentPair.first;

		int componentIndex = this->entityComponents.at(id)->at(componentType);
		std::vector<Component>* componentVectorPtr = (std::vector<Component>*) this->components.at(componentType);

		// Deactivate the component
		componentVectorPtr->at(componentIndex).isActive = false;

		// Add the component to the queue of components to be reused
		this->deletedComponents.at(componentType)->push(componentIndex);
	}

	// Remove the entity from the entityComponents map
	SAFE_DELETE(this->entityComponents.at(id));
	this->entityComponents.erase(id);

	// Remove the entity from the entityFamilies map
	this->entityFamilies.at(entityTypeId)->erase(id);

	// Remove the entity from the list of entities
	SAFE_DELETE(this->entities.at(id));
	this->entities.erase(id);
}

void Manager::releaseAll() {
	// Delete all entities
	// Create a copy of the entity ids and types
	std::vector<std::pair<EntityIdType, Types::TypeId>> entityCopy;
	entityCopy.reserve(this->entities.size());

	for (auto kv : this->entities)
	{
		EntityIdType entityId = kv.first;
		Types::TypeId entityType = kv.second->getTypeId();
		entityCopy.push_back(std::make_pair(entityId, entityType));
	}

	for (auto pair : entityCopy)
	{
		this->removeEntity(pair.first, pair.second);
	}

	// Clean up entityFamilies
	for (auto kv : this->entityFamilies)
	{
		SAFE_DELETE(kv.second);
	}
	this->entityFamilies.clear();

	// Clean up components
	for (auto kv : this->components)
	{
		SAFE_DELETE(kv.second);
	}
	this->components.clear();

	// Clean up deleted queues
	for (auto kv : this->deletedComponents)
	{
		SAFE_DELETE(kv.second);
	}
	this->deletedComponents.clear();

	// Clean up entityComponents
	for (auto kv : this->entityComponents)
	{
		SAFE_DELETE(kv.second);
	}
	this->entityComponents.clear();
}

}
