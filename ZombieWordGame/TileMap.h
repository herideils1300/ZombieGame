#pragma once
#include "Mappable.h"
#include "Tile.h"

class TileMap : public Mappable
{
private:
	const std::map<char, Tile> defaultMapping = {
		{'#', Tile(new Color(ORANGE), this->env)},
		{'.', Tile(new Color(WHITE), this->env)},
		{'\n', Tile(this->env)}
	};

public:
	TileMap(const char* map, EnvironmentObserver* env) : Mappable(map, env) {}
	void draw();
};

