#include "Bullet.h"
#include "Element.h"
#include <raylib.h>


void Bullet::travel()
{
	this->pos = this->calc.addTwoVectors(this->pos, this->step);
}

void Bullet::disperse()
{
	this->isDispersed = false;
}

Vector2 Bullet::giveStep()
{
	return Vector2{ this->speed / cosf(this->rotation), this->speed / sinf(this->rotation) };
}

void Bullet::update()
{
	if (this->calc.calculateDistance(this->pos.x - this->orgPos.x, this->pos.y - this->orgPos.y) < this->distance) { return; };
	this->travel();
}

void Bullet::draw()
{
	if (this->calc.calculateDistance(this->pos.x - this->orgPos.x, this->pos.y - this->orgPos.y) < this->distance) { return; };
	DrawRectanglePro(Rectangle{ this->pos.x, this->pos.y, 5.0f, 5.0f }, Vector2{ 2.5f, 2.5f }, this->rotation, ColorFromHSV(180, 100, 20));
}