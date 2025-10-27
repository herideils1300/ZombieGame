#include "Player.h"
#include "Bullet.h"
#define DEGREE_SCALE 57.2957795
#define RAY_COLOR ColorFromHSV(100, 120, 88)
#define DEAD_CONDITION if(!this->alive) {return;}

void Player::onDie()
{
	this->alive = false;
}

void Player::onGetHit(float damage)
{
	this->health -= 20.0f;
}

void Player::updateMove()
{

	Vector2 posValue = this->pos;
	float moveSpeed = 0.0f;

	if (!this->isAiming)
		moveSpeed = (IsKeyDown(KEY_LEFT_SHIFT)) ? this->stats.sprintSpeed : this->stats.walkSpeed;
	else
		moveSpeed = this->stats.aimMoveSpeed;

	this->isSprinting = (moveSpeed == this->stats.sprintSpeed);
	Vector2 step = Vector2{ (float)(IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * moveSpeed, (float)(IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * moveSpeed };
	this->pos = calc.addTwoVectors(this->pos, step);
	this->boundingBox = Rectangle{ this->pos.x, this->pos.y, this->charWidth, this->charHeight };
}

void Player::updateAim()
{
	//Rotation following mouse button
	if (!this->isSprinting) {
		Vector2 mousePos = GetMousePosition();
		this->rotation = this->calc.alphaAngleCalcualte((mousePos.x - this->pos.x), (mousePos.y - this->pos.y)) * RAD2DEG;
	}
	else {
		Vector2 step = Vector2{ (float)(IsKeyDown(KEY_D) - IsKeyDown(KEY_A)), (float)(IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) };
		this->rotation = this->calc.alphaAngleCalcualte((step.x), (step.y)) * RAD2DEG;
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
	if (this->isAiming) {
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			Bullet* bullet = new Bullet();
			this->isShooting = true;
			this->env->sendAttack(bullet);
		}
	}

}



void Player::init()
{
}

void Player::update()
{
	DEAD_CONDITION;
	this->updateAim();
	this->updateFire();
	this->updateMove();
}

void Player::draw()
{
	DEAD_CONDITION;
	DrawRectanglePro(this->boundingBox, Vector2{ (float)this->boundingBox.width / 2, (float)this->boundingBox.height / 2 }, this->rotation, ColorFromHSV(100, 120, 88));
	if (this->isAiming)
	{
		DrawLine(this->pos.x, this->pos.y, GetMouseX(), GetMouseY(), RAY_COLOR);
	}
}
