#pragma once
#include <string>
#include "MapSegment.h"
#include "Element.h"
#include "Tile.h"

class Mappable : public Element
{
protected:
	int width = 0, height = 0;
	const char* map;
public:
	Mappable(const char* map, EnvironmentObserver* env) : Element(env), map(map) {}
	virtual void init() {};
	virtual void updateAt(int x, int y) {};
	virtual void draw() {};
	void setMap(const char* map);

};

