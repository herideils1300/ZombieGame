#include "ClientScene.h"
#include "Player.h"

void ClientScene::sendMapUpdate()
{
}

void ClientScene::sendPlayerPositionUpdate()
{
}

void ClientScene::recieveUpdateEnv()
{
}

void ClientScene::loop()
{
	//Window
	bool gameOver = false;
	int winWidth = 640;
	int winHeight = 480;
	const char* title = "Zombies";

	InitWindow(winWidth, winHeight, title);
	SetTargetFPS(60);

	// -- clear color
	Color backgroundColor = ColorFromHSV(0, 0, 0);


	Player* player = new Player(env);

	while (!gameOver)
	{
		ClearBackground(backgroundColor);

		env->updateEnv();
		BeginMode2D(env->getCamera(player->pos, { 0, 0 }, 0.0f, 1.0f));
		env->drawEnv();
		EndMode2D();

		if (IsKeyPressed(KEY_Q) || WindowShouldClose()) {
			gameOver = true;
		}
	}
}
