#pragma once
#include "Element.h"
#include "Alive.h"
class Camera
{
private:
	int x = 0, y = 0;
	int offsetX = 0, offsetY = 0;
public:
	Camera() {};
	void setPosition(int x, int y);
	void follow(Alive* alive);
	void offset(int x, int y);
	void affectEnvironment(std::vector<Element*> all);
	~Camera() {};

};

