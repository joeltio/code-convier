#include "GameLevelComponent.h"


namespace Component {

	bool GameLevel::isOnSamePlatform(float x1, float y1, float x2, float y2) {
		
		//change scale of positions
		x1 /= tileWidth;
		y1 /= tileHeight;
		x2 /= tileWidth;
		y2 /= tileHeight;

		int xDiff = x1 - x2;

		//read map file
		std::ifstream map;
		std::vector<std::string> mapvector;
		map.open("./map/temp.txt");
		while (map) {
			std::string line;
			std::getline(map, line);
			if (line != "")
			{
				mapvector.push_back(line);
			}
		}

		//check y axis of 1 and 2
		std::string solidTiles = SOLID_TILES;
		if (y1 == y2)
		{
			if (solidTiles.find(mapvector[(int)y1 + 1][(int)x1]) == std::string::npos)
			{
				return false;
			}
			else if (solidTiles.find(mapvector[(int)y2 + 1][(int)x2]) == std::string::npos)
			{
				return false;
			}

			if (xDiff > 0)
			{
				for (size_t i = (int)x2; i < mapvector[(int)(y2+1)][i]; i++)
				{
					if (solidTiles.find(mapvector[(int)y1 + 1][i] == std::string::npos)) {
						return false;
					}
				}

			}
			else if (xDiff < 0)
			{
				for (size_t i = (int)x1; i < mapvector[(int)(y1 + 1)][i]; i++)
				{
					if (solidTiles.find(mapvector[(int)y2 + 1][i] == std::string::npos)) {
						return false;
					}
				}
			}
			return true;
		}
		else
		{
			return false;
		}

	}

}