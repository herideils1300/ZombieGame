#include "Attack.h"
#include "Alive.h"

void Attack::init(Vector2 pos, float angle)
{
	this->pos = pos;
	this->orgPos = pos;
	this->rotation = angle;
	this->env->sendAttack(this);
}
