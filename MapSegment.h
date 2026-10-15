#pragma once
#include <functional>
#include "Alive.h"

struct MapSegment : public InEnvironment
{
public:
	MapSegment();
	MapSegment(EnvironmentObserver* env) : InEnvironment(env) {
		this->x = x;
		this->y = y;
	};
	MapSegment(std::function<void(Alive* alive)> action, EnvironmentObserver* env) : InEnvironment(env) {
		this->x = x;
		this->y = y;
		this->action = action;
	};
	int x = 0, y = 0;
	std::function<void(Alive* alive)> action = [](Alive* alive) {};
};

