#include "Environment.h"
#include "Alive.h"


Environment::Environment(std::vector<Alive*> elements)
{
	for (Alive* e : elements) {
		e->setEnv(this);
		this->elements.push_back(e);
	}
}

void Environment::broadcast(Alive* root, SignalType type)
{
	float maxDistance = 600.0f;
	float damage = 100.0f;
	for (Element* el : this->elements) {
		switch (type)
		{
		case SHOOT:
			if (calc.isRectOnInfinteLine(el->boundingBox, root->boundingBox, maxDistance, root->rotation)) {
				((Alive*)el)->hit(100.0f);
			}
			break;
		case SWING:
			break;
		case SPOT:
			break;
		case LOSE:
			break;
		default:
			break;
		}

	}
}
