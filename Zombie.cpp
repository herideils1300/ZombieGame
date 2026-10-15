#include "Zombie.h"
#include "PhysicsDefinition.h"

void Zombie::locateTarget()
{
	std::vector<Element*> targets = this->env->getByAngleInbetween(this->pos, this->rotation, 10.0f);

	for (Element* target : targets) {
		Alive* aliveTarget = dynamic_cast<Alive*>(target);
		if (aliveTarget == nullptr || !aliveTarget->isAlive()) {
			continue;
		}
		this->onSpot(aliveTarget);
		break;
	}

}

void Zombie::moveTowardsTarget()
{
	if (this->target == nullptr || !this->target->isAlive()) {
		return;
	}

	if (!VectorCalculator::areVectorsTheSameAproximately(this->pos, target->pos, this->attackRange))
	{
		Vector2 step = VectorCalculator::normalizeVector(Vector2{ (float)((target->pos.x > this->pos.x) - (target->pos.x < this->pos.x)), (float)((target->pos.y > this->pos.y) - (target->pos.y < this->pos.y)) });
		this->pos = VectorCalculator::addTwoVectors(this->pos, VectorCalculator::multplyVector(step, this->stats.sprintSpeed));
		this->rotation = VectorCalculator::alphaAngleCalculate((step.x), (step.y));
		this->boundingBox = Rectangle{ this->pos.x, this->pos.y, (float)this->charWidth, (float)this->charHeight };
	}
	else {
		attack();
	}
}

void Zombie::attack()
{
	float attackDamage = 20.0f;
	
	Hit* hit = new Hit(this->env);
	hit->init(this);
	this->env->addAttack(hit);
}

void Zombie::onSpot(Alive* spotted)
{
	this->target = spotted;
}

void Zombie::onGetHit(float damage)
{
	Alive::onGetHit(damage);
}

void Zombie::init()
{
	this->target = nullptr;
	this->stats.sprintSpeed = RUN_SPEED;
}

void Zombie::update()
{
	if (!this->alive) {
		return;
	}

	updateAlive();
	locateTarget();
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
	if (!this->isAlive()) {
		return;
	}

	this->drawElement();
}
