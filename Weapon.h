#pragma once
#include <raylib.h>
#include "Environment.h"

class Weapon
{
protected:
	float damage = 10.0f;
	int maxNumberOfAttacks = 0;
public:
	Weapon(float damage, float maxNumberOfAttacks) {
		this->damage = damage;
		this->maxNumberOfAttacks = maxNumberOfAttacks;
	};
	Weapon(float damage) {
		this->damage = damage;
	};
	virtual Attack* initAttack(Vector2 position, float rotation, EnvironmentObserver* env) {
		return nullptr;
	};
};

