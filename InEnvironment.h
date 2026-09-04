#pragma once
#include "Environment.h"

class InEnvironment {
public:
	EnvironmentObserver* env;

	InEnvironment(EnvironmentObserver* env) {
		this->env = env;
	};

	void addToEnv(Attack* element) {
		if (this->env != nullptr) {
			this->env->addAttack(element);
		}
	}
};
