#pragma once
#include "Element.h"
#include "InEnvironment.h"
#include "StatsStruct.h"
#include "VectorCalculator.h"
#include <raylib.h>
#include <time.h>


class Alive : public Element, public InEnvironment {
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

	//Events
	virtual void onGetHit(float damage) {
		this->health -= damage;
	};
	virtual void onDie() {
		this->alive = false;
	};

	virtual void onSpot(Alive* spotted) {};

	//Constant reuse functions

	//Self checks if its alive or dead and updates
	void updateAlive() {
		if (this->health <= 0.0f) {
			onDie();
		}
	}
public:
	Alive() : Element(), InEnvironment() {};
	Alive(Vector2 pos, float rotation) : Element(pos, rotation), InEnvironment() {};

	

	//Environment usage
	void hit(float damage) {
		this->onGetHit(damage);
	}

	void spot(Alive* alive) {
		this->onSpot(alive);
	}

	bool isDead() {
		return this->alive;
	}




};
