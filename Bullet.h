#pragma once
#include <raylib.h>
#include "VectorCalculator.h"
#include "Attack.h"

class Bullet : public Attack
{
private:
	VectorCalculator calc = VectorCalculator();
	Vector2 step = Vector2();
	float speed = 5.0f;
	void travel();
	void disperse();
public:
	Bullet() : Attack() {};
	Vector2 giveStep();
	void update() override;
	void draw() override;

};

