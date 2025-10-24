#pragma once
#include <raylib.h>
#include "VectorCalculator.h"
#include "Element.h"

class Bullet : public Element
{
private:
	VectorCalculator calc = VectorCalculator();
	float speed = 5.0f;
public:
	Bullet() {};
	void travel(Vector2 step);
	void scanForHit(float width);
	void disperse();
};

