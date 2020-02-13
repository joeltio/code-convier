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
	//Form game level
	std::string gameLevel;
	for (size_t i = 0; i < gamemap.size(); i++)
	{
		gameLevel += gamemap[i];
	}
	//Store game level in temp map file
	std::ofstream tempMap("./map/temp.txt", std::ofstream::out | std::ofstream::trunc);
	for (size_t i = 0; i < gamemap.size(); i++)
	{
		if (i%(mapFragment+2) == 0)
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
	for (size_t y = 0; y < gamemap.size(); y++)
	{
		for (size_t x = 0; x < gamemap[y].size(); x++)
		{
			if (gamemap[y][x] == 'P') {
				ECS::EntityIdType playerId = Entity::Player::create(this->manager, this->graphics, ((float) x * tileWidth), ((float) y * tileHeight));
			}
		}
	}

	return FSM::NoAction();
}