#include "Player.h"
#define DEGREE_SCALE 57.2957795
#define RAY_COLOR ColorFromHSV(100, 120, 88)
#define DEAD_CONDITION if(!this->alive) {return;}

void Player::updateMove()
{
	DEAD_CONDITION;

	Vector2 posValue = this->pos;
	float moveSpeed = 0.0f;

	if (!this->isAiming)
		moveSpeed = (IsKeyDown(KEY_LEFT_SHIFT)) ? this->stats.sprintSpeed : this->stats.walkSpeed;
	else
		moveSpeed = this->stats.aimMoveSpeed;

	this->isSprinting = (moveSpeed == this->stats.sprintSpeed);
	this->pos = calc.addTwoVectors(this->pos, Vector2{ (float)(IsKeyDown(KEY_D) - IsKeyDown(KEY_A))* moveSpeed, (float)(IsKeyDown(KEY_S) - IsKeyDown(KEY_W))* moveSpeed });
	this->boundingBox = Rectangle{ this->pos.x, this->pos.y, this->charWidth, this->charHeight };
}

void Player::updateAim()
{
	DEAD_CONDITION;
	//Rotation following mouse button
	if (!this->isSprinting) {
		Vector2 mousePos = GetMousePosition();
		this->rotation = this->calc.alphaAngleCalcualte((mousePos.x - this->pos.x), (mousePos.y - this->pos.y)) * RAD2DEG;
	}

	// Aim logic; Draws a line towards the cursor when aiming
	float runtimeAccuracy = this->stats.accuracy;
	float angle = PI / runtimeAccuracy;

	if (this->isAiming) {
		runtimeAccuracy += this->stats.aimSpeed;
		if (this->isShooting) {
			runtimeAccuracy -= 10; //AccuracyLevel;
			this->isShooting = false;
		}
	}
	else {
		float accuracy = 4;
		float angle = PI / accuracy;
	}

	this->isAiming = IsMouseButtonDown(MOUSE_BUTTON_RIGHT);

}

void Player::updateFire()
{
	DEAD_CONDITION;
	if (this->isAiming) {
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			this->isShooting = true;
			this->env->broadcast(this, SignalType::SHOOT);
		}
	}

}



void Player::init()
{
}

void Player::update()
{
	this->updateAim();
	this->updateFire();
	this->updateMove();
}

void Player::draw()
{

	DrawRectanglePro(this->boundingBox, Vector2{ (float)this->boundingBox.width / 2, (float)this->boundingBox.height / 2 }, this->rotation, ColorFromHSV(100, 120, 88));
	if (this->isAiming)
	{
		DrawLine(this->pos.x, this->pos.y, GetMouseX(), GetMouseY(), RAY_COLOR);
	}
}
