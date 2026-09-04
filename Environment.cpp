#include "Environment.h"
#include "Alive.h"
#include "Bullet.h"
#include <tuple>


EnvironmentObserver::EnvironmentObserver(std::vector<Element*> elements)
{
}

std::vector<Element*> EnvironmentObserver::getByCoordinates(Vector2 root, float radius)
{
	std::vector<Element*> elementsInRadius = std::vector<Element*>();
	for (Element* element : this->elements) {
		if (this->calc.isVectorInRadius(element->pos, root, radius)) {
			elementsInRadius.push_back(element);
		}
	}
	return elementsInRadius;
}

void EnvironmentObserver::addAttack(Attack* attack)
{
	this->attacks.push_back(attack);
}

void EnvironmentObserver::addElement(Element* element)
{
	this->elements.push_back(element);
}

void EnvironmentObserver::initEnv(std::vector<Element*> elements)
{
	this->elements = elements;
	for (Element* element : this->elements) {
		element->init();
	}
}

void EnvironmentObserver::updateEnv()
{
	for (Attack* attack : this->attacks) {
		attack->update();
	}

	for (Element* element : this->elements) {
		element->update();
	}
}

void EnvironmentObserver::drawEnv()
{
	for (Attack* attack : this->attacks) {
		attack->draw();
	}

	for (Element* element : this->elements) {
		element->draw();
	}
}
