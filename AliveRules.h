#pragma once
#include <vector>
#include "Alive.h"
#include "VectorCalculator.h"
class AliveRules {
private:
	std::vector<Alive*> elements;
	VectorCalculator calc = VectorCalculator();
public:
	AliveRules(std::vector<Alive*>& elements) {
		this->elements = elements;
	}

	void checkSpotted(Alive* sender) {
		for (Alive* alive : elements) {
			if (alive == sender) {
				continue;
			}
		}
	}

};
