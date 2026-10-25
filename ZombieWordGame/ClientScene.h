#pragma once
#include <raylib.h>
#include "Environment.h"

class ClientScene
{
private:
	Camera2D camera = Camera2D { 0 };
	EnvironmentObserver* env;
public:
	ClientScene(EnvironmentObserver* env) {
		this->env = env;
	};
	ClientScene(std::vector<Element*> elements) {
		env = new EnvironmentObserver(elements);
	};

	void sendMapUpdate();
	void sendPlayerPositionUpdate();
	void recieveUpdateEnv();
	void loop();

};

