#pragma once
#include "Attack.h"
#include "Alive.h"
class Hit : public Attack
{
private:
	Alive* parent = nullptr;
	float frameMeter = 0;
	float startAngle = 0.0f;
	float endAngle = 45.0f;
	float angle;
	void swing();
	bool moveAndAttack();
public:
	Hit(EnvironmentObserver* env) : Attack(env) {};
	void init(Alive* parent);
	void update() override;
	void draw() override;
	void disperse() { this->isDispersed = true; };
	bool isSwinging();
	void follow();
};

