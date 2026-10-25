#pragma once
#include <raylib.h>
#include "PhysicsDefinition.h"
#include "VectorCalculator.h"
#include "Attack.h"
#include "Alive.h"

class Bullet : public Attack
{
private:
	Vector2 step = Vector2();
	bool isActive = false;
	float distance = BULLET_DISTANCE;
	float speed = BULLET_SPEED;
	void travelAndAttack();
	void checkDisperse();
public:
	Bullet(Vector2 position, float rotation, EnvironmentObserver* env) : Attack(env) {
		this->pos = position;
		this->rotation = rotation;
		this->step = VectorCalculator::calculateStep(this->speed, this->rotation);
	};

	Vector2 giveStep();
	void update() override;
	void draw() override;
};

