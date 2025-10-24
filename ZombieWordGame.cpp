
#include <iostream>
#include <raylib.h>
#include "Player.h"
#include "Zombie.h"
#include <typeinfo>



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




	//Character
	std::vector<Alive*> characters = {
		new Player(),
		new Zombie(Vector2{ 100.0f, 100.0f }, 0.0f)
	};

	Environment* env = new Environment(characters);

	for (Alive* ch : characters) {
		ch->init();
	}


	while (!gameOver)
	{
		ClearBackground(backgroundColor);
		for (Alive* ch : characters) {
			ch->update();
		}
		BeginDrawing();
		for (Alive* ch : characters) {
			ch->draw();
		}
		EndDrawing();
		if (IsKeyPressed(KEY_Q)) {
			gameOver = true;
		}
	}
}

