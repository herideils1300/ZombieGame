#pragma once
#include <raylib.h>
#include <functional>
#include "MapSegment.h"


class Tile : public MapSegment
{
private:
	int x = 0, y = 0;
	const char* texturePath;
	Color* color;
public:
	Tile(EnvironmentObserver* env) : MapSegment(env) {};
	Tile(Color* color, EnvironmentObserver* env) : MapSegment(env), color(color), texturePath(nullptr) {};
	Tile(const char* texturePath, EnvironmentObserver* env) : MapSegment(env), texturePath(texturePath), color(nullptr) {};
	Tile(const char* texturePath, std::function<void(Alive* alive)> action, EnvironmentObserver* env) : MapSegment(action, env), texturePath("") {};
	bool isAliveNearby();
	void setTexturePath(const char* path);
	void executeAction(Alive* alive);
	void assignCoordinates(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void draw();
};

