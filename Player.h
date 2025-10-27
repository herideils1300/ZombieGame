#pragma once
#include <raylib.h>
#include "Alive.h"
#include "VectorCalculator.h"

class Player : public Alive
{
private:

	bool isShooting = false;
	bool isAiming = false;
	bool isSprinting = false;

	//Dependencies
	VectorCalculator calc = VectorCalculator();

	void onDie() override;
	void onGetHit(float damage) override;


	void updateMove();
	void updateAim();
	void updateFire();
public:
	Player() : Alive() {};
	Player(Vector2 pos, float rotation, StatsStruct stats) : Alive(pos, rotation) {
		this->stats = stats;
	}
	void init() override;
	void update() override;
	void draw() override;

};

