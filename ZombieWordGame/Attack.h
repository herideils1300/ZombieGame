#pragma once
#include "Element.h"


class Attack : public Element
{
protected:
	bool isDispersed = false;
	Vector2 orgPos = Vector2();
	float damage = 50.0f;
	bool isRanged = true;
public:
	Attack(EnvironmentObserver* env) : Element(env) {};
	virtual void init(Vector2 pos, float angle) {};
	virtual void update() {};
	virtual void draw() {};
	bool getIsDispersed() { return this->isDispersed; }
};

