#include "Zombie.h"

void Zombie::locateTarget()
{
	if (this->target == nullptr) {
		float alpha = 85.0f;
		float fieldOfVision = 20.0f;
	}
}

void Zombie::moveTowardsTarget()
{
	if (this->target == nullptr || !this->target->isDead()) {
		return;
	}

	if (!calc.areVectorsTheSameAproximately(this->pos, target->pos, this->attackRange))
	{
		Vector2 step = Vector2{ (float)((target->pos.x > this->pos.x) - (target->pos.x < this->pos.x)) * this->stats.sprintSpeed, (float)((target->pos.y > this->pos.y) - (target->pos.y < this->pos.y)) * this->stats.sprintSpeed };
		this->pos = calc.addTwoVectors(this->pos, step);
		this->rotation = calc.alphaAngleCalcualte((step.x * 10.0f - this->pos.x), (step.y * 10.0f - this->pos.y));
		this->boundingBox = Rectangle{ this->pos.x, this->pos.y, (float)this->charWidth, (float)this->charHeight };
	}
	else {
		attack();
	}
}

void Zombie::attack()
{
	float attackDamage = 20.0f;
	this->target->hit(attackDamage);
}

void Zombie::drawPov()
{
	Vector2 root = this->pos;
}

void Zombie::onSpot(Alive* spotted)
{
	this->target = spotted;
}

void Zombie::die() {
	this->target = nullptr;
}

void Zombie::onGetHit(float damage)
{
	this->health -= damage;
}

void Zombie::onDie()
{
	this->alive = false;
}

void Zombie::init(Alive* element)
{
	this->target = element;
	this->stats.sprintSpeed = 2.0f;
}

void Zombie::update()
{
	updateAlive();
	moveTowardsTarget();
}

void Zombie::draw()
{
	if (!this->alive) {
		return;
	}

	Rectangle rect = Rectangle{ this->pos.x, this->pos.y, (float)this->charWidth, (float)this->charHeight };
	Vector2 origin = Vector2{ (float)this->charWidth / 2, (float)this->charHeight / 2 };
	DrawRectanglePro(rect, origin, this->rotation, this->characterColor);
}
