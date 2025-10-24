#include "Bullet.h"
#include "Element.h"

void Bullet::travel(Vector2 step)
{
	this->pos = calc.addTwoVectors(this->pos, step);
}

void Bullet::scanForHit(float width = 0.5) 
{
}

void Bullet::disperse()
{
}
