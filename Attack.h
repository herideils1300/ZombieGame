#pragma once
#include "Element.h"


class Attack : public Element
{
protected:
	VectorCalculator calc = VectorCalculator();
	bool isActive = false;
	float distance = 600.0f;
	float speed = 5.0f;
public:
	bool isDispersed = true;
	Vector2 orgPos = Vector2();
	float damage = 50.0f;
	bool isRanged = true;
	Attack() : Element() {};
	void init(Vector2 pos, float angle);
	virtual void update() {};
	virtual void draw() {};
};

