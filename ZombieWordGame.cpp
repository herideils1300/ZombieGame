
#include <iostream>
#include <raylib.h>
#include "Player.h"
#include "Zombie.h"
#include <typeinfo>
#include "Environment.h"



int main() {
	//Window
	bool gameOver = false;
	int winWidth = 640;
	int winHeight = 480;
	const char* title = "Zombies";

	InitWindow(640, 480, title);
	SetTargetFPS(60);

	// -- clear color
	Color backgroundColor = ColorFromHSV(0, 0, 0);


	EnvironmentObserver* env = new EnvironmentObserver();

	//Character
	std::vector<Element*> elements = {
		new Player(env),
		new Zombie(Vector2{ 100.0f, 100.0f }, 0.0f, env)
	};

	env->initEnv(elements);

	while (!gameOver)
	{
		ClearBackground(backgroundColor);

		env->updateEnv();

		BeginDrawing();
		env->drawEnv();
		EndDrawing();

		if (IsKeyPressed(KEY_Q)) {
			gameOver = true;
		}
	}
}

