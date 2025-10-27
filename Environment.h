#pragma once
#include "VectorCalculator.h"
#include <vector>
#include <map>
#include <functional>
#include <raylib.h>


class Element;
class Alive;
class Attack;

class Environment {
private:
	int deletedElements = 0;
	int deletedAttacks = 0;
	std::vector<Element*> elements = std::vector<Element*>();
	std::vector<Attack*> attacks = std::vector<Attack*>();
	VectorCalculator calc = VectorCalculator();
	int getAttackIndexIfAffecting(Alive* target);
public:
	Environment() = default;
	Environment(std::vector<Element*> elements);
	void clearAllStep();
	void sendAttack(Attack* attack);
	void updateElements();
	void updateAttacks();
	Attack* recieveAttack(Alive* target);
};
