#include "Gun.h"
#include "Bullet.h"
#include "Environment.h"

Bullet* Gun::initAttack(Vector2 pos, float rot, EnvironmentObserver* env)
{
	return new Bullet(pos, rot, env);
}
