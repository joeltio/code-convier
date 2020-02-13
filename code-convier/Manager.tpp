#include "Manager.h"

namespace ECS {

template<typename EntityType> EntityIdType Manager::createEntity() {
	// Create the entity
	Types::TypeId entityType = Types::toTypeId<EntityType>();
	EntityIdType newEntityId = Entity::createEntityId(this->lastCreatedEntityId);
	Entity* entity = new Entity(newEntityId, entityType);

	// Add the entity to the entities map
	std::pair<EntityIdType, Entity*> entityRecord (newEntityId, entity);
	this->entities.insert(entityRecord);

	// Add the entity to the entityFamilies map
	if (this->entityFamilies.find(entityType) == this->entityFamilies.end())
	{
		// Add an empty set with the entityType if it does not exist
		std::unordered_set<EntityIdType>* emptySet = new std::unordered_set<EntityIdType>();
		std::pair<Types::TypeId, std::unordered_set<EntityIdType>*> emptyRecord
			(entityType, emptySet);
		this->entityFamilies.insert(emptyRecord);
	}
	this->entityFamilies.at(entityType)->insert(newEntityId);

	// Update the last created entity
	this->lastCreatedEntityId = newEntityId;

	return newEntityId;
}

template<typename ComponentType> std::vector<ComponentType>* Manager::getComponents() {
	// Ensure that the ComponentType is a Component
	static_assert(
		std::is_base_of<Component, ComponentType>::value,
		"Attempting to getComponents of non-Component type"
	);

	Types::TypeId componentTypeId = Types::toTypeId<ComponentType>();

	return (std::vector<ComponentType>*) this->getComponents(componentTypeId);
}

template<typename ComponentType> ComponentType& Manager::getEntityComponent(EntityIdType id) {
	// Ensure that the ComponentType is a Component
	static_assert(
		std::is_base_of<Component, ComponentType>::value,
		"Attempting to getComponents of non-Component type"
	);

	Types::TypeId componentTypeId = Types::toTypeId<ComponentType>();
	int componentIndex = this->entityComponents.at(id)->at(componentTypeId);
	std::vector<ComponentType>* componentVectorPtr = (std::vector<ComponentType>*) this->components.at(componentTypeId);
	return (ComponentType&) componentVectorPtr->at(componentIndex);
}

template<typename EntityType> std::unordered_set<EntityIdType>* Manager::getEntities() {
	Types::TypeId entityType = Types::toTypeId<EntityType>();

	return this->getEntities(entityType);
}

template<typename ComponentType> bool Manager::entityHasComponent(EntityIdType id) {
	Types::TypeId componentTypeId = Types::toTypeId<ComponentType>();

	std::unordered_map<Types::TypeId, int>* entityComponents = this->entityComponents.at(id);
	return entityComponents->find(componentTypeId) != entityComponents->end();
}

template<typename EntityType> void Manager::removeEntity(EntityIdType id) {
	Types::TypeId entityTypeId = Types::toTypeId<EntityType>();

	this->removeEntity(id, entityTypeId);
}

template<typename ComponentType> void Manager::addComponent(EntityIdType id, ComponentType component) {
	Types::TypeId componentTypeId = Types::toTypeId<ComponentType>();

	if (this->components.find(componentTypeId) == this->components.end())
	{
		// Add an empty vector with the componentType if it does not exist
		std::pair<Types::TypeId, std::vector<ComponentType>*> emptyRecord
			(componentTypeId, new std::vector<ComponentType>());
		this->components.insert(emptyRecord);
	}

	std::vector<ComponentType>* componentVectorPtr = (std::vector<ComponentType>*) this->components.at(componentTypeId);

	if (this->deletedComponents.find(componentTypeId) == this->deletedComponents.end())
	{
		std::pair<Types::TypeId, std::queue<int>*> emptyRecord
			(componentTypeId, new std::queue<int>());
		this->deletedComponents.insert(emptyRecord);
	}

	// Set the entity id
	component.entityId = id;

	// Add the component to the manager
	int componentIndex = -1;
	if (!this->deletedComponents.at(componentTypeId)->empty())
	{
		// Reuse old components
		componentIndex = this->deletedComponents.at(componentTypeId)->front();
		this->deletedComponents.at(componentTypeId)->pop();

		// Set the reused component's values to the new components values
		componentVectorPtr->at(componentIndex) = component;
	}
	else
	{
		// Add the new component
		componentVectorPtr->push_back(component);
		componentIndex = componentVectorPtr->size() - 1;
	}

	// Add to the entity components
	// Check if there is a map for the entity id
	if (this->entityComponents.find(id) == this->entityComponents.end())
	{
		// Create an empty map
		std::unordered_map<Types::TypeId, int>* emptyMap = new std::unordered_map<Types::TypeId, int>();
		// Add the map to the entity components map
		std::pair<EntityIdType, std::unordered_map<Types::TypeId, int>*> emptyRecord =
			std::make_pair(id, emptyMap);
		this->entityComponents.insert(emptyRecord);
	}

	std::pair<Types::TypeId, int> componentIndexPair = std::make_pair(componentTypeId, componentIndex);
	this->entityComponents.at(id)->insert(componentIndexPair);

	// Add retriever
	// Check if there is already a retriever
	if (this->componentRetriever.find(componentTypeId) == this->componentRetriever.end())
	{
		std::pair<int, std::function<Component* (std::vector<Component>* componentsPtr, size_t)>> retriever =
			std::make_pair(
				0,
				[](std::vector<Component>* componentsPtr, size_t index) {
					return &(((std::vector<ComponentType>*) componentsPtr)->at(index));
				}
			);

		auto record = std::make_pair(componentTypeId, retriever);
		this->componentRetriever.insert(record);
	}

	this->componentRetriever.at(componentTypeId).first = this->getComponents<ComponentType>()->size();
}

}
