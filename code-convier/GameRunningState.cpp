#include "GameRunningState.h"

FSM::Action GameRunningState::update(float frameTime, Component::State state) {
	if (this->input->isKeyDown(VK_ESCAPE)) {
		return PauseGameAction();
	}

	ECS::EntityIdType gameID = *this->manager->getEntities<Entity::Game>()->begin();
	Component::GameState& gameState = this->manager->getEntityComponent<Component::GameState>(gameID);

	float xCenter = 0;
	float yCenter = 0;
	std::unordered_set<ECS::EntityIdType>* players = this->manager->getEntities<Entity::Player>();

	for (ECS::EntityIdType playerId : *players)
	{
		Component::Transform playerPosition = this->manager->getEntityComponent<Component::Transform>(playerId);
		xCenter += playerPosition.x;
		yCenter += playerPosition.y;
	}

	xCenter /= players->size();
	yCenter /= players->size();

	float offsetX = xCenter - (GAME_WIDTH / 2);
	float offsetY = yCenter - (GAME_HEIGHT / 2);

	gameState.renderRect.left = offsetX;
	gameState.renderRect.right = offsetX + GAME_WIDTH;
	gameState.renderRect.top = offsetY;
	gameState.renderRect.bottom = offsetY + GAME_HEIGHT;

	if (gameState.renderRect.left < 0)
	{
		gameState.renderRect.left = 0;
		gameState.renderRect.right = GAME_WIDTH;
	}

	if (gameState.renderRect.right > levelWidth* tileWidth)
	{
		gameState.renderRect.right = levelWidth * tileWidth;
		gameState.renderRect.left = gameState.renderRect.right - GAME_WIDTH;
	}

	if (gameState.renderRect.top < 0)
	{
		gameState.renderRect.top = 0;
		gameState.renderRect.bottom = GAME_HEIGHT;
	}

	if (gameState.renderRect.bottom > levelHeight* tileHeight)
	{
		gameState.renderRect.bottom = levelHeight * tileHeight;
		gameState.renderRect.top = gameState.renderRect.bottom - GAME_HEIGHT;
	}

	return FSM::NoAction();
}