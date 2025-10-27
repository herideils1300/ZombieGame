#pragma once
#include <raylib.h>
#include <math.h>
#include <vector>
#include <iostream>

class VectorCalculator {
public:
	Vector2 addTwoVectors(Vector2 one, Vector2 two) {
		Vector2 result = Vector2();

		result.x = one.x + two.x;
		result.y = one.y + two.y;

		return result;
	}

	bool areVectorsTheSame(Vector2 one, Vector2 two) {
		return one.x == two.x && one.y == two.y;
	}

	bool areVectorsTheSameAproximately(Vector2 one, Vector2 two, float threshold) {
		if (threshold <= 0) {
			throw "The threshold in the aproximate equation of vectors mus be positive;";
		}

		return fabsf(one.x - two.x) < threshold && fabsf(one.y - two.y) < threshold;
	}

	Vector2 multplyVector(Vector2 vector, float multiplier) {
		return Vector2{ vector.x * multiplier, vector.y * multiplier };
	}

	Vector2 normalizeVector(Vector2 vector) {
		float nominal = this->calculateDistance(vector.x, vector.y);
		Vector2 normalizedVector = { vector.x / nominal, vector.y / nominal };
		return normalizedVector;
	}

	float calculateDistance(float divX, float divY) {
		return sqrtf(pow(divX, 2) + pow(divY, 2));
	}

	bool isVectorInRectangle(Vector2 vec, Rectangle rect) {
		return (vec.x >= rect.x && vec.y >= rect.y && vec.x <= rect.width && vec.y <= rect.height);
	}

	bool isRectOnInfinteLine(Rectangle rectangle, Rectangle root, float maxDistance, float angle) {

		if (rectangle.x == root.x && rectangle.y == root.y) {
			return false;
		}

		float treshold = rectangle.width / 2;
		float divX = rectangle.x - root.x;
		float divY = rectangle.y - root.y;
		float distance = this->calculateDistance(divX, divY);

		float angleX = fabsf(distance * cos(angle * DEG2RAD) - divX);
		float angleY = fabsf(distance * sin(angle * DEG2RAD) - divY);

		bool isHit = (angleX < treshold && angleY < treshold && distance <= maxDistance);

		return isHit;
	}

	bool isRectOnStepPath(Rectangle rectangle, Vector2 start, Vector2 step) {
		float stepAngle = this->alphaAngleCalcualte(step.x, step.y);
		float distance = this->calculateDistance(step.x, step.y);
		float angle = this->alphaAngleCalcualte(step.x, step.y);

		bool isWithinStep = (rectangle.x >= start.x && rectangle.x <= (start.x + step.x) && rectangle.y >= start.y && rectangle.y <= (start.y + step.y));
		bool isOnStepPath = this->isRectOnInfinteLine(rectangle, Rectangle{ start.x, start.y, 0, 0 }, distance, angle);
		
		return isWithinStep && isOnStepPath;
	}

	bool isVectorInRadius(Vector2 vec, Vector2 radCenter, float radius) {
		float divX = radCenter.x - vec.x;
		float divY = radCenter.y - vec.y;

		float distance = this->calculateDistance(divX, divY);

		bool isInRadius = (distance < radius);

		return isInRadius;
	}

	Vector2 calculateStepDirection() {

	}

	bool isVectorInTriangle(Vector2 position, Vector2 root, float width, float height, float angle) {
		float divX = position.x - root.x;
		float divY = position.y - root.y;

		float tresholdAngle = atanf(height / (width / 2));
		float positionAngle = this->alphaAngleCalcualte(divX, divY);

		float distance = this->calculateDistance(divX, divY);

		bool isInTriangle = (fabsf(positionAngle - angle * DEG2RAD) < tresholdAngle && distance < height);

		std::cout << isInTriangle << std::endl;

		return isInTriangle;
	}



	float alphaAngleCalcualte(float divX, float divY) {
		//divX = fabsf(divX);
		//divY = fabsf(divY);
		return (divX <= 0) ? atan(divY / divX) + PI : atan(divY / divX);
	};


	VectorCalculator() = default;
};