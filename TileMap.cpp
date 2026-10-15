#include "TileMap.h"

void TileMap::draw() {
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 50; j++)
		{
			Tile tile = this->defaultMapping.at(this->map[j + i * 49]);
			tile.assignCoordinates(j, i);
			tile.draw();
		}
	}
}