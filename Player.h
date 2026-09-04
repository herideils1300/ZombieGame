#pragma once
#include <raylib.h>
#include "PhysicsDefinition.h"
#include "Alive.h"
#include "VectorCalculator.h"
#include "Weapon.h"
#include "Gun.h"


class Player : public Alive
{
private:

	bool isShooting = false;
	bool isAiming = false;
	bool isSprinting = false;

	//Dependencies
	VectorCalculator calc = VectorCalculator();
	Weapon* weapon = new Gun(10.0f /* Damage */, 5 /* Max Number of Attacks */);

	void onDie();
	void onGetHit(float damage);


	void updateMove();
	void updateAim();
	void updateFire();
public:
	Player(EnvironmentObserver* env) : Alive(env) {};
	Player(Vector2 pos, float rotation, StatsStruct stats, EnvironmentObserver* env) : Alive(pos, rotation, env) {
		this->stats = stats;
	}
	void init() override;
	void update() override;
	void draw() override;

};

