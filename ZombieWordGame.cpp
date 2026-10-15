
#include <iostream>
#include <raylib.h>
#include "Player.h"
#include "Zombie.h"
#include <typeinfo>
#include "Environment.h"
#include "TileMap.h"


int main() {
	//Window
	bool gameOver = false;
	int winWidth = 640;
	int winHeight = 480;
	const char* title = "Zombies";

	InitWindow(winWidth, winHeight, title);
	SetTargetFPS(60);

	// -- clear color
	Color backgroundColor = ColorFromHSV(0, 0, 0);


	EnvironmentObserver* env = new EnvironmentObserver();

	const char* mapString =
		"################################################\n"
		"################################################\n"
		"################################################\n"
		"################################################\n"
		"################################################\n"
		"################################################\n"
		"################################################\n"
		"################################################\n"
		"################################################\n"
		"################################################\n"
		"################################################\n"
		"################################################\n"
		"################################################\n"
		"################################################\n"
		"################################################\n"
		"################################################\n"
		"################################################\n"
		"################################################\n"
		"################################################\n"
		"################################################\n"
		"################################################\n";

	//Character
	std::vector<Element*> elements = {
		new TileMap(mapString, env),
		new Player(env)
	};

	env->initEnv(elements);

	while (!gameOver)
	{
		ClearBackground(backgroundColor);

		env->updateEnv();

		BeginDrawing();
		env->drawEnv();
		EndDrawing();

		if (IsKeyPressed(KEY_Q) || WindowShouldClose()) {
			gameOver = true;
		}
	}
}

