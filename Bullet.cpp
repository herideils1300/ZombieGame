#include "Bullet.h"
#include "Element.h"
#include <raylib.h>

void Bullet::travelAndAttack()
{
	//Travel
	this->pos = this->calc.addTwoVectors(this->pos, this->step);

	//Attack
	std::vector<Element*> elementsInRadius = this->env->getByCoordinates(this->pos, 15.0f);

	for (Element* element : elementsInRadius) {
		Alive* aliveElement = dynamic_cast<Alive*>(element);

		if (aliveElement == NULL) {
			continue;
		}

		if (aliveElement != nullptr && aliveElement->isAlive() && this->calc.isRectOnStepPath(aliveElement->boundingBox, this->pos, this->step)) {
			aliveElement->hit(this->damage);
			this->isDispersed = true;
			break;
		}
	}
}

void Bullet::checkDisperse()
{
	this->isDispersed = this->calc.calculateDistance(this->pos.x - this->orgPos.x, this->pos.y - this->orgPos.y) > this->distance;
}

Vector2 Bullet::giveStep()
{
	return this->step;
}

void Bullet::update()
{
	if (!this->isDispersed) {
		this->travelAndAttack();
		this->checkDisperse();
	}

}

void Bullet::draw()
{
	if (this->isDispersed) { return; };
	DrawRectanglePro(Rectangle{ this->pos.x, this->pos.y, 5.0f, 5.0f }, Vector2{ 2.5f, 2.5f }, this->rotation, ColorFromHSV(180, 100, 20));
}