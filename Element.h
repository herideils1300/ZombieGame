#pragma once
#include <raylib.h>
#include <time.h>
#include <random>
#include "InEnvironment.h"

class Element : public InEnvironment
{
public:
	virtual void init() {};
	virtual void update() {};
	virtual void draw() {};

	//Mechanics
	Vector2 pos;
	float rotation = 0.0f;
	Rectangle boundingBox;

	//Graphics
	Color characterColor = ColorFromHSV(100, 120, 88);
	float charWidth = 32.0f;
	float charHeight = 32.0f;

	Element() : InEnvironment() {
		srand(time(NULL));

		this->pos.x = (float)(rand() % 640);
		this->pos.y = (float)(rand() % 480);

		this->boundingBox = Rectangle{ this->pos.x, this->pos.y, charWidth, charHeight };
	};
	Element(Vector2 pos, float rotation) : InEnvironment() {
		this->pos = pos;
		this->rotation = rotation;

		this->boundingBox = Rectangle{ this->pos.x, this->pos.y, charWidth, charHeight };
	};

};

