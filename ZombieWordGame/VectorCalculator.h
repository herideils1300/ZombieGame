#pragma once
#include <raylib.h>
#include <math.h>
#include <vector>
#include <iostream>

class VectorCalculator {
public:
	static Vector2 addTwoVectors(Vector2 one, Vector2 two) {
		Vector2 result = Vector2();

		result.x = one.x + two.x;
		result.y = one.y + two.y;

		return result;
	}

	static bool areVectorsTheSame(Vector2 one, Vector2 two) {
		return one.x == two.x && one.y == two.y;
	}

	static bool areVectorsTheSameAproximately(Vector2 one, Vector2 two, float threshold) {
		if (threshold <= 0) {
			throw "The threshold in the aproximate equation of vectors mus be positive;";
		}

		return fabsf(one.x - two.x) < threshold && fabsf(one.y - two.y) < threshold;
	}

	static Vector2 multplyVector(Vector2 vector, float multiplier) {
		return Vector2{ vector.x * multiplier, vector.y * multiplier };
	}

	static Vector2 normalizeVector(Vector2 vector) {
		float nominal = calculateDistance(vector.x, vector.y);
		Vector2 normalizedVector = { vector.x / nominal, vector.y / nominal };
		return normalizedVector;
	}

	static float calculateDistance(float divX, float divY) {
		return sqrtf(powf(divX, 2) + powf(divY, 2));
	}

	static bool isVectorInRectangle(Vector2 vec, Rectangle rect) {
		return (vec.x >= rect.x && vec.y >= rect.y && vec.x <= rect.width && vec.y <= rect.height);
	}

	static bool isRectOnInfinteLine(Rectangle rectangle, Rectangle root, float maxDistance, float angle) {
		if (rectangle.x == root.x && rectangle.y == root.y) {
			return false;
		}

		float treshold = rectangle.width / 2;
		float divX = rectangle.x - root.x;
		float divY = rectangle.y - root.y;
		float distance = calculateDistance(divX, divY);

		float angleX = fabsf(distance * cos(angle * DEG2RAD) - divX);
		float angleY = fabsf(distance * sin(angle * DEG2RAD) - divY);

		std::cout << "X" << angleX << " Y" << angleY << std::endl;

		bool isHit = (angleX < treshold && angleY < treshold && distance <= maxDistance);

		return isHit;
	}

	static bool isRectOnStepPath(Rectangle rectangle, Vector2 start, Vector2 step) {
		float stepAngle = alphaAngleCalculate(step.x - start.x, step.y - start.y);
		float distance = calculateDistance(rectangle.x - step.x, rectangle.y - step.y);
		float stepDistance = calculateDistance(step.x - start.x, step.y - start.y);

		bool isWithinStepDistance = (distance <= stepDistance);
		bool isOnStepPath = isRectOnInfinteLine(rectangle, Rectangle{ start.x, start.y, 0, 0 }, stepDistance, stepAngle);
		
		return isWithinStepDistance && isOnStepPath;
	}

	static bool isVectorInRadius(Vector2 vec, Vector2 radCenter, float radius) {
		float divX = radCenter.x - vec.x;
		float divY = radCenter.y - vec.y;

		float distance = calculateDistance(divX, divY);
		bool isInRadius = (distance < radius);

		return isInRadius;
	}

	static Vector2 calculateStep(float speed, float angle) {
		return multplyVector(normalizeVector(Vector2{ cosf(angle * DEG2RAD), sinf(angle * DEG2RAD)}), speed);
	}

	static bool isVectorBetweenAngles(Vector2 root, Vector2 target, float angle, float thershold) {
		float requiredAngle = alphaAngleCalculate(target.x - root.x, target.y - root.y) * DEG2RAD;
		return requiredAngle < angle + thershold && requiredAngle > angle - thershold;	
	}

	static bool isVectorInTriangle(Vector2 position, Vector2 root, float width, float height, float angle) {
		float divX = position.x - root.x;
		float divY = position.y - root.y;

		float tresholdAngle = atanf(height / (width / 2));
		float positionAngle = alphaAngleCalculate(divX, divY);

		float distance = calculateDistance(divX, divY);

		bool isInTriangle = (fabsf(positionAngle - angle * DEG2RAD) < tresholdAngle && distance < height);

		std::cout << isInTriangle << std::endl;

		return isInTriangle;
	}



	static float alphaAngleCalculate(float divX, float divY) {
		//divX = fabsf(divX);
		//divY = fabsf(divY);
		return (divX <= 0) ? (atan(divY / divX) + PI) * RAD2DEG : atan(divY / divX) * RAD2DEG;
	};


	VectorCalculator() = delete;
};