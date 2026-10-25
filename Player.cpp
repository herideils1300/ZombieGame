#include "Player.h"
#include "Bullet.h"
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
	float moveSpeed = 0.0f;

	if (!this->isAiming)
		moveSpeed = (IsKeyDown(KEY_LEFT_SHIFT)) ? this->stats.sprintSpeed : this->stats.walkSpeed;
	else
		moveSpeed = this->stats.aimMoveSpeed;

	this->isSprinting = (moveSpeed == this->stats.sprintSpeed);
	Vector2 step = Vector2{ (float)(IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * moveSpeed, (float)(IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * moveSpeed };
	this->pos = VectorCalculator::addTwoVectors(this->pos, step);

	this->boundingBox = Rectangle{ this->pos.x, this->pos.y, this->charWidth, this->charHeight };
}

void Player::updateAim()
{
	//Rotation following mouse button

	Vector2 step = Vector2{ (float)(IsKeyDown(KEY_D) - IsKeyDown(KEY_A)), (float)(IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) };

	if (this->isSprinting && step.x != 0 && step.y != 0) {
		this->rotation = VectorCalculator::alphaAngleCalculate((step.x), (step.y));
	}
	else {
		Vector2 mousePos = GetMousePosition();
		this->rotation = VectorCalculator::alphaAngleCalculate((mousePos.x - this->pos.x), (mousePos.y - this->pos.y));
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
	if (!this->isAiming) {
		return;
	}

	if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		return;
	}

	if (this->weapon == nullptr) {
		// Use fists to hit (binded to Alive entity) if there is no weapon equipped
		Hit* hit = new Hit(this->env);
		hit->init(this);
		this->env->addAttack(hit);
	}
	else {
		// Use weapon to fire
		Attack* attack = this->weapon->fire(this->pos, this->rotation, this->env);
		this->env->addAttack(attack);
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
	if (this->isAiming && this->weapon != nullptr)
	{
		this->weapon->aim(this->pos, this->rotation);
	}
}
