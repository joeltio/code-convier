#include "GameCreateLevelState.h"

FSM::Action GameCreateLevelState::update(float frameTime, Component::State state) {

	//Create rng map
	std::vector<int> maplist;
	for (size_t i = 0; i < mapFragment; i++)
	{
		int id = rand()%5 + 1;
		maplist.push_back(id);
	}
	//Open starting map file
	std::vector<std::string> startmap;
	std::ifstream start;
	start.open("./map/start.txt");
	while (start) {
		std::string line;
		std::getline(start, line);
		startmap.push_back(line);
	}
	//Open rng maplist
	std::vector<std::vector<std::string>> rng;
	for (size_t i = 0; i < maplist.size(); i++)
	{
		std::ifstream map;
		map.open(".\map\map" + std::to_string(maplist[i]) + ".txt");
		std::vector<std::string> rngmap;
		while (map) {
			std::string line;
			std::getline(map, line);
			rngmap.push_back(line);
		}
		rng.push_back(rngmap);
	}
	//Rearange randomized map using another vector
	std::vector<int> arrange;
	for (size_t i = 0; i < rng.size(); i++)
	{
		int order = (int)(i / levelHeight) + mapFragment * (i % levelHeight);
		arrange.push_back(order);
	}
	for (size_t i = 0, d; i < rng.size(); i++)
	{
		for (d = arrange[i]; d < i; d = arrange[d]);
		if (d == i) while (d = arrange[d], d != i) {
			std::swap(rng[i], rng[d]);
		}
	}
	//Form game level
	/*for (size_t i = 0; i < rng.size(); i++)
	{

	}*/
	
	for (size_t y = 0; y < startmap.size(); y++)
	{
		for (size_t x = 0; x < startmap[y].size(); x++)
		{
			if (startmap[y][x] == 'P') {
				ECS::EntityIdType playerId = Entity::Player::create(this->manager, this->graphics, ((float) x * tileWidth), ((float) y * tileHeight));
			}
		}
	}

	return FSM::NoAction();
}