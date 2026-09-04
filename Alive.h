#pragma once
#include "Element.h"
#include "StatsStruct.h"
#include "VectorCalculator.h"
#include <raylib.h>
#include <time.h>


class Attack;


class Alive : public Element {
protected:
	StatsStruct stats = StatsStruct(
		GripStrength::solid,
		MoveSpeed::runner,
		AimSpeed::soldier,
		Stamina::joe
	);

	float health = 100.0f;

	bool alive = true;
	VectorCalculator calc = VectorCalculator();

	//Event when the alive element is hit and takes damage.
	virtual void onGetHit(float damage) {
		this->health -= damage;
	};

	//Event when the alive element dies. Sets alive to false.
	void onDie() {
		this->alive = false;
	};

	//Checks the death of the alive element and calls onDie() if health is 0 or less.
	void checkDeath() {
		if (this->health <= 0.0f) {
			this->onDie();
		}
	};

	virtual void onSpot(Alive* spotted) {};

	//Self checks if its alive or dead and updates
	void updateAlive() {
		if (this->health <= 0.0f) {
			onDie();
		}
	}
public:
	Alive(EnvironmentObserver* env) : Element(env) {};
	Alive(Vector2 pos, float rotation, EnvironmentObserver* env) : Element(pos, rotation, env) {};

	//Used as an outside function to damage this Alive element.
	void hit(float damage) {
		this->onGetHit(damage);
		this->checkDeath();
	};

	//Returns the alive status of this Alive element. True if alive, false if dead.
	bool isAlive() {
		return this->alive;
	};

	


};
