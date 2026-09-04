#pragma once
#include "raylib.h"
#include "Element.h"
#include "VectorCalculator.h"
#include "Bullet.h"
#include <vector>
class VectorSearch
{
public:
	VectorCalculator calc = VectorCalculator();

	/*std::vector<Element*> searchBulletHit(std::vector<Element*> elements, Bullet* attack) {
		std::vector<Element*> hitElements = std::vector<Element*>();

		for (Element* element : elements) {

			bool isHit = calc.isRectOnStepPath(element->boundingBox, attack->pos, attack->giveStep());
			if (isHit) {
				hitElements.push_back(element);
			}
		}

		return hitElements;
	}*/

};

