#pragma once
#include "Weapon.h"
#include "Environment.h"
#include <raylib.h>
#include "Bullet.h"

class Gun : public Weapon
{
private:
	int numberOfAttacks;
public:
	Gun(float damage, int maxNumberOfAttacks) : Weapon(damage, maxNumberOfAttacks) {
		this->numberOfAttacks = maxNumberOfAttacks;
	};
	Bullet* fire(Vector2 pos, float rot, EnvironmentObserver* env) override;
	void aim(Vector2 position, float rotation) override;
};

