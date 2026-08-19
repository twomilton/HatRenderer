#pragma once

struct Mat4
{
	float m[4][4]{};

	static Mat4 identity();

	static Mat4 translation(
		float x,
		float y,
		float z
	);

	static Mat4 rotationZ(
		float radians
	);
};