#pragma once
#include "MechanicsEnums.h"
struct StatsStruct
{
	float accuracy = 4.0f;
	float aimSpeed = 0.3f;
	float aimMoveSpeed = 1.0f;
	float walkSpeed = 2.0f;
	float sprintSpeed = 4.0f;

	StatsStruct(
		GripStrength gs,
		MoveSpeed ms,
		AimSpeed as,
		Stamina s
		) {
		//TODO: Logic for updating floats
	}

	void updateStats() {

	}

};
