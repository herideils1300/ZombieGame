#pragma once
#include "Environment.h"

class InEnvironment {
public:
	Environment* env = new Environment();
	InEnvironment() {
		this->env = nullptr;
	};
	void setEnv(Environment* env) {
		this->env = env;
	}
};
