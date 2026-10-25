#include "Hit.h"
#include "VectorCalculator.h"
#include "BehaviourDefinitions.h"

void Hit::swing()
{
	bool isAliveHit = moveAndAttack();
	if (this->angle > this->endAngle || isAliveHit) {
		this->isDispersed = true;
	}

	this->angle += 5.0f;
}

bool Hit::moveAndAttack()
{
	std::vector<Element*> elementsInRadius = this->env->getByCoordinates(this->pos, 50.0f);

	for (Element* element : elementsInRadius) {
		Alive* aliveElement = dynamic_cast<Alive*>(element);

		if (aliveElement == nullptr || aliveElement == this->parent) {
			continue;
		}

		if (VectorCalculator::isRectOnStepPath(aliveElement->boundingBox, this->pos, VectorCalculator::calculateStep(20.0f, this->angle))) {
			aliveElement->hit(this->damage);
			return true;
		}
	}

	return false;
}

void Hit::init(Alive* parent)
{
	this->pos = VectorCalculator::addTwoVectors(parent->pos, VectorCalculator::calculateStep(32.0f /*Attack distance*/, parent->rotation));
	this->rotation = parent->rotation;
	this->angle = this->rotation - 45.0f;
	this->endAngle = this->rotation + 45.0f;
	this->isDispersed = false;
	this->parent = parent;
}

void Hit::update()
{
	if (!this->isDispersed) {
		swing();
		follow();
	}
}

void Hit::draw()
{
	if (!this->isDispersed) {
		Vector2 step = VectorCalculator::calculateStep(32.0f, this->angle);
		DrawLine(this->parent->pos.x, this->parent->pos.y, this->parent->pos.x + step.x, this->parent->pos.y + step.y, WHITE);
	}
}

bool Hit::isSwinging()
{
	return this->frameMeter != 0.0f;
}

void Hit::follow()
{
	if (isSwinging()) {
		Vector2 step = VectorCalculator::calculateStep(20.0f, this->angle);
		this->pos = VectorCalculator::addTwoVectors(parent->pos, step);
	}

}
