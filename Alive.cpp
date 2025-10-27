#include "Alive.h"
#include "Bullet.h"

void Alive::checkHit()
{

}

void Alive::spot(Alive* alive)
{
	this->onSpot(alive);
}

bool Alive::isAlive()
{
	return this->alive;
}
