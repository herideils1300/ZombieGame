#include "Gun.h"
#include "Bullet.h"
#include "Environment.h"

Bullet* Gun::fire(Vector2 pos, float rot, EnvironmentObserver* env)
{
	return new Bullet(pos, rot, env);
}

void Gun::aim(Vector2 position, float rotation)
{
	DrawLine(position.x, position.y, GetMouseX(), GetMouseY(), BLUE);
}
