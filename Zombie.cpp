#include "Zombie.h"

void Zombie::locateTarget()
{
	if (this->target == nullptr) {
		//Implement locating target
	}
}

void Zombie::moveTowardsTarget()
{
	if (this->target == nullptr || !this->target->isAlive()) {
		return;
	}

	if (!calc.areVectorsTheSameAproximately(this->pos, target->pos, this->attackRange))
	{
		Vector2 step = Vector2{ (float)((target->pos.x > this->pos.x) - (target->pos.x < this->pos.x)), (float)((target->pos.y > this->pos.y) - (target->pos.y < this->pos.y)) };
		this->pos = calc.addTwoVectors(this->pos, calc.multplyVector(step, this->stats.sprintSpeed));
		this->rotation = this->calc.alphaAngleCalcualte((step.x), (step.y)) * RAD2DEG;
		this->boundingBox = Rectangle{ this->pos.x, this->pos.y, (float)this->charWidth, (float)this->charHeight };
	}
	else {
		attack();
	}
}

void Zombie::attack()
{
	float attackDamage = 20.0f;
	//TODO: Implement attack
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

void Zombie::init()
{
	this->target = nullptr;
	this->stats.sprintSpeed = 2.0f;
}

void Zombie::update()
{
	locateTarget();
	updateAlive();
	moveTowardsTarget();
}

void Zombie::drawPov()
{
	float width = 100.0f;
	float height = 100.0f;

	DrawRectanglePro(Rectangle{ this->pos.x + this->charWidth/2, this->pos.y, width, height }, Vector2{ 0, height / 2}, this->rotation, ColorFromHSV(50, 150, 40));
}

void Zombie::drawElement()
{
	Rectangle rect = Rectangle{ this->pos.x, this->pos.y, (float)this->charWidth, (float)this->charHeight };
	Vector2 origin = Vector2{ (float)this->charWidth / 2, (float)this->charHeight / 2 };
	DrawRectanglePro(rect, origin, this->rotation, this->characterColor);
}

void Zombie::draw()
{
	if (!this->alive) {
		return;
	}

	this->drawElement();
}
