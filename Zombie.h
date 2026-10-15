#pragma once
#include "Element.h"
#include "Alive.h"
#include "VectorCalculator.h"
#include "signal.h"
#include "StatsStruct.h"

class Zombie : public Alive
{
private:
	//Graphics
	Color characterColor = ColorFromHSV(130, 200, 20);
	StatsStruct stats = StatsStruct(
		GripStrength::solid,
		MoveSpeed::runner,
		AimSpeed::soldier,
		Stamina::joe
	);

	//Mechanics
	Alive* target = nullptr;
	float attackRange = 10.0f;
	float damage = 20.0f;
	Vector2 povPoints[2];

	//update func
	void locateTarget();
	void moveTowardsTarget();
	void attack();

	//draw funcs
	void drawPov();
	void drawElement();

	//Dictates events on hit
	void onGetHit(float damage) override;

	//Events
	void onSpot(Alive* spotted) override;


public:
	Zombie(Vector2 pos, float rotation, EnvironmentObserver* env) : Alive(pos, rotation, env) {};
	void init() override;
	void update() override;
	void draw() override;
};

