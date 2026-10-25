#include "Camera.h"

void Camera::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Camera::follow(Alive* alive)
{
	this->x = alive->pos.x;
	this->y = alive->pos.y;
}

void Camera::offset(int x, int y)
{
	this->offsetX = x;
	this->offsetY = y;
}

void Camera::affectEnvironment(std::vector<Element*> all)
{
	for(Element* element : all)
	{
		element->boundingBox.x -= this->x - this->offsetX;
		element->boundingBox.y -= this->y - this->offsetY;
	}
}
