#include "GameDestroyLevelState.h"

void GameDestroyLevelState::enter(Component::State state) {
	std::unordered_set<ECS::EntityIdType> solidTilesIds = *this->manager->getEntities<Entity::SolidTile>();
	std::unordered_set<ECS::EntityIdType> decorateTilesIds = *this->manager->getEntities<Entity::DecorativeTile>();
	std::unordered_set<ECS::EntityIdType> playerId = *this->manager->getEntities<Entity::Player>();
	std::unordered_set<ECS::EntityIdType> enemiesIds = *this->manager->getEntities<Entity::Enemy>();
	std::unordered_set<ECS::EntityIdType> runningIconIds = *this->manager->getEntities<Entity::PlayerRunningIcon>();
	std::unordered_set<ECS::EntityIdType> chargingIconIds = *this->manager->getEntities<Entity::PlayerChargingIcon>();
	std::unordered_set<ECS::EntityIdType> healthBarIds = *this->manager->getEntities<Entity::Healthbar>();

	for (ECS::EntityIdType solidTilesId : solidTilesIds)
	{
		this->manager->removeEntity<Entity::SolidTile>(solidTilesId);
	}
	for (ECS::EntityIdType decorateTilesId : decorateTilesIds)
	{
		this->manager->removeEntity<Entity::DecorativeTile>(decorateTilesId);
	}
	for (ECS::EntityIdType player : playerId)
	{
		this->manager->removeEntity<Entity::Player>(player);
	}
	for (ECS::EntityIdType enemyId : enemiesIds)
	{
		this->manager->removeEntity<Entity::Enemy>(enemyId);
	}
	for (ECS::EntityIdType runningIconId : runningIconIds)
	{
		this->manager->removeEntity<Entity::PlayerRunningIcon>(runningIconId);
	}
	for (ECS::EntityIdType chargingIconId : chargingIconIds)
	{
		this->manager->removeEntity<Entity::PlayerChargingIcon>(chargingIconId);
	}
	for (ECS::EntityIdType healthBarId : healthBarIds)
	{
		this->manager->removeEntity<Entity::Healthbar>(healthBarId);
	}

	Component::GameState gameState = this->manager->getEntityComponent<Component::GameState>(state.entityId);


}

void GameDestroyLevelState::exit(Component::State state) {

}

FSM::Action GameDestroyLevelState::update(float frametime, Component::State state) {
	return FSM::NoAction();
}