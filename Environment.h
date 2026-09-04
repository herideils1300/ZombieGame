#pragma once
#include "VectorCalculator.h"
#include <vector>
#include <map>
#include <functional>
#include <raylib.h>


class Element;
class Alive;
class Attack;

class EnvironmentObserver {
private:
	int deletedElements = 0;
	int deletedAttacks = 0;
	std::vector<Attack*> attacks = std::vector<Attack*>();
	std::vector<Element*> elements = std::vector<Element*>();
	VectorCalculator calc = VectorCalculator();
public:
	EnvironmentObserver() = default;
	EnvironmentObserver(std::vector<Element*> elements);
	std::vector<Element*> getByCoordinates(Vector2 root, float radius);
	void addAttack(Attack* attack);
	void addElement(Element* element);
	void initEnv(std::vector<Element*> elements);
	void updateEnv();
	void drawEnv();
};
