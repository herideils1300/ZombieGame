#pragma once
#include <raylib.h>
#include "PhysicsDefinition.h"
#include "VectorCalculator.h"
#include "Attack.h"
#include "Alive.h"
#include "VectorSearch.h"

class Bullet : public Attack
{
private:
	VectorSearch search = VectorSearch();
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
		this->step = this->calc.calculateStep(this->speed, this->rotation);
	};

	Vector2 giveStep();
	void update() override;
	void draw() override;

};

