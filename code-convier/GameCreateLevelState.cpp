#include "GameCreateLevelState.h"

//on enter
void GameCreateLevelState::enter(Component::State state) {

	std::string decoTiles = DECORATIVE_TILES;
	std::string solidTiles = SOLID_TILES;

	//Create rng map
	std::vector<int> maplist;
	for (size_t i = 0; i < mapFragment; i++)
	{
		int id = rand() % 6;
		maplist.push_back(id);
	}
	//Open starting map file
	std::vector<std::string> gamemap;
	std::ifstream start;
	start.open("./map/start.txt");
	while (start) {
		std::string line;
		std::getline(start, line);
		if (line != "")
		{
			gamemap.push_back(line);
		}
	}
	//Open end map file
	std::vector<std::string> endmap;
	std::ifstream end;
	end.open("./map/end.txt");
	while (end) {
		std::string line;
		std::getline(end, line);
		if (line != "")
		{
			endmap.push_back(line);
		}
	}
	//Open rng maplist
	std::vector<std::string> rng;
	for (size_t i = 0; i < maplist.size(); i++)
	{
		std::ifstream map;
		map.open("./map/map" + std::to_string(maplist[i]) + ".txt");
		while (map) {
			std::string line;
			std::getline(map, line);
			if (line != "")
			{
				rng.push_back(line);
			}
		}
	}
	//Combine start and end to randomized maps
	gamemap.insert(gamemap.end(), rng.begin(), rng.end());
	gamemap.insert(gamemap.end(), endmap.begin(), endmap.end());
	//Rearange randomized map using another vector
	std::vector<int> arrange;
	for (size_t i = 0; i < gamemap.size(); i++)
	{
		int order = (int)(i / levelHeight) + (mapFragment + 2) * (i % levelHeight);
		arrange.push_back(order);
	}
	for (size_t i = 0, d; i < gamemap.size(); i++)
	{
		for (d = arrange[i]; d < i; d = arrange[d]);
		if (d == i) while (d = arrange[d], d != i) {
			std::swap(gamemap[i], gamemap[d]);
		}
	}
	//Store game level in temp map file
	std::ofstream tempMap("./map/temp.txt", std::ofstream::out | std::ofstream::trunc);
	for (size_t i = 0; i < gamemap.size(); i++)
	{
		if (i % (mapFragment + 2) == 0)
		{
			tempMap << std::endl << gamemap[i];
		}
		else
		{
			tempMap << gamemap[i];
		}
	}
	tempMap.close();
	//Generate level
	std::vector<std::string> level;
	std::ifstream gamelevel;
	gamelevel.open("./map/temp.txt");
	while (gamelevel) {
		std::string line;
		std::getline(gamelevel, line);
		if (line != "")
		{
			level.push_back(line);
		}
	}
	int playerX;
	int playerY;
	for (size_t y = 0; y < level.size(); y++)
	{
		for (size_t x = 0; x < level[y].size(); x++)
		{
			if (solidTiles.find(level[y][x]) != std::string::npos)
			{
				Entity::SolidTile::create(this->manager, this->graphics, ((float)x * tileWidth), ((float)y * tileHeight), level[y][x]);
			}
			else if (level[y][x] == ' ')
			{
				Entity::DecorativeTile::create(this->manager, this->graphics, ((float)x * tileWidth), ((float)y * tileHeight), ' ');
			}
			else if (level[y][x] == '*') {
				Entity::DecorativeTile::create(this->manager, this->graphics, ((float)x* tileWidth), ((float)y* tileHeight), ' ');
				Entity::DecorativeTile::create(this->manager, this->graphics, ((float)x* tileWidth), ((float)y* tileHeight), '*');
			}
			else if (level[y][x] == '$')
			{
				Entity::DecorativeTile::create(this->manager, this->graphics, ((float)x * tileWidth), ((float)y * tileHeight), '$');
			}
			else if (level[y][x] == 'P')
			{
				Entity::DecorativeTile::create(this->manager, this->graphics, ((float)x* tileWidth), ((float)y* tileHeight), ' ');
				playerX = x;
				playerY = y;
			}
		}
	}
	Entity::Player::create(this->manager, this->graphics, ((float)playerX * tileWidth), ((float)playerY * tileHeight));

	//spawn enermy
	std::vector<std::vector<int>> enemyList;
	while (enemyList.size() != ENEMY_COUNT)
	{
		int randomX = rand() % levelWidth;
		int randomY = rand() % levelHeight;

		if (randomY >= levelHeight - 2 || randomX <= 12)
		{
			continue;
		}
		char enemySpawnTop = level[randomY][randomX];
		char enemySpawnBottom = level[randomY + 1][randomX];
		char enemyOnBlock = level[randomY + 2][randomX];
		
		if (decoTiles.find(enemySpawnTop) != std::string::npos && decoTiles.find(enemySpawnBottom) != std::string::npos && solidTiles.find(enemyOnBlock) != std::string::npos)
		{
			std::vector<int> enemyPosition;
			enemyPosition.push_back(randomX);
			enemyPosition.push_back(randomY);
			enemyList.push_back(enemyPosition);
			Entity::Enemy::create(this->manager, this->graphics, ((float)randomX* tileWidth), ((float)randomY* tileHeight));
		}
	}
	Entity::Healthbar::create(this->manager, this->graphics);
	Entity::PlayerRunningIcon::create(this->manager, this->graphics, 0.9 * GAME_WIDTH, 0.025 * GAME_HEIGHT);
	Entity::PlayerChargingIcon::create(this->manager, this->graphics, 0.8 * GAME_WIDTH, 0.025 * GAME_HEIGHT);
}

//on update
FSM::Action GameCreateLevelState::update(float frameTime, Component::State state) {
	return ResumeGameAction();
}

//on exit
void GameCreateLevelState::exit(Component::State state) {

}