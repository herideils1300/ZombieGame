#include "Tile.h"

bool Tile::isAliveNearby()
{
	return this->env->getByCoordinates(Vector2{ (float)this->x, (float)this->y }, 50.0f).size() == 0;
}

void Tile::setTexturePath(const char* path)
{
	this->texturePath = path;
}

void Tile::executeAction(Alive* alive)
{
	this->action(alive);
}

void Tile::draw(){
	if (this->color != nullptr) {
		DrawRectanglePro(Rectangle{ this->x * DIMENSIONALITY, this->y * DIMENSIONALITY, DIMENSIONALITY, DIMENSIONALITY }, Vector2{ DIMENSIONALITY / 2, DIMENSIONALITY / 2 }, 0.0f, *this->color);
	}
	else if(this->texturePath != NULL) {
		DrawTexturePro(LoadTexture(this->texturePath), Rectangle{ 0, 0, (float)DIMENSIONALITY, (float)DIMENSIONALITY }, Rectangle{ this->x * DIMENSIONALITY, this->y * DIMENSIONALITY, (float)DIMENSIONALITY, (float)DIMENSIONALITY }, Vector2{ 0, 0 }, 0.0f, WHITE);
	}
	else {
		return;
	}

	if (this->isAliveNearby()) {
		DrawText("E", this->x * DIMENSIONALITY, this->y - 25.0f * DIMENSIONALITY, 20, RED);
	}
}
