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
	Alive() : Element() {};
	Alive(Vector2 pos, float rotation) : Element(pos, rotation) {};

	

	//Environment usage
	void checkHit();

	void spot(Alive* alive);

	bool isAlive();




};
