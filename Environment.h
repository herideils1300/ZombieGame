#pragma once
#include "VectorCalculator.h"
#include "SingalTypes.h"
#include <vector>

class Element;
class Alive;


class Environment {
private:
	std::vector<Element*> elements = std::vector<Element*>();
	VectorCalculator calc = VectorCalculator();
public:
	Environment() = default;
	Environment(std::vector<Alive*> elements);
	void broadcast(Alive* root, SignalType type);
};
