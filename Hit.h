#pragma once
#include "Attack.h"
class Hit : public Attack
{
private:
	float distance = 10.0f;
	float angleInDegrees = 30.0f;
public:
	Hit(EnvironmentObserver* env) : Attack(env) {};
	void update() override;
	void draw() override;
};

