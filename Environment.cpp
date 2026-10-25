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
		if (VectorCalculator::isVectorInRadius(element->pos, root, radius)) {
			elementsInRadius.push_back(element);
		}
	}
	return elementsInRadius;
}

std::vector<Element*> EnvironmentObserver::getByAngleInbetween(Vector2 root, float angle, float plusMinusThershold)
{
	std::vector<Element*> betweenElements = std::vector<Element*>();
	for (Element* element : this->elements) {
		if (VectorCalculator::isVectorBetweenAngles(root, element->pos, angle, plusMinusThershold * DEG2RAD)) {
			betweenElements.push_back(element);
		}
	}
	return betweenElements;
}

Camera2D EnvironmentObserver::getCamera(Vector2 position, Vector2 offset, float rotation, float zoom)
{
	this->camera.offset = offset;
	this->camera.target = position;
	this->camera.rotation = rotation;
	this->camera.zoom = zoom;
	return this->camera;
}

void EnvironmentObserver::freeElements()
{
	for (int i = 0; i < this->attacks.size(); i++) {
		if (this->attacks[i]->getIsDispersed()) {
			delete this->attacks[i];
			this->attacks[i] = nullptr;

		}
	}

	std::erase(this->attacks, nullptr);
	this->attacks.shrink_to_fit();
}

void EnvironmentObserver::addAttack(Attack* attack)
{
	if (this->attacks.size() > 10) {
		freeElements();
	}
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

	this->camera.target = this->elements[0]->pos;
}

void EnvironmentObserver::drawEnv()
{

	BeginDrawing();

	for (Attack* attack : this->attacks) {
		attack->draw();
	}

	for (Element* element : this->elements) {
		element->draw();
	}

	EndDrawing();
}
