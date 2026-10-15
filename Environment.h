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
	void freeElements();
public:
	EnvironmentObserver() = default;
	EnvironmentObserver(std::vector<Element*> elements);
	~EnvironmentObserver() {
		for (Element* element : this->elements) {
			delete element;
		}
		for (Attack* attack : this->attacks) {
			delete attack;
		}
	};
	std::vector<Element*> getByCoordinates(Vector2 root, float radius);
	std::vector<Element*> getByAngleInbetween(Vector2 root, float angle, float plusMinusThershold);
	void addAttack(Attack* attack);
	void addElement(Element* element);
	void initEnv(std::vector<Element*> elements);
	void updateEnv();
	void drawEnv();
};
