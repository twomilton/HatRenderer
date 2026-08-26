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

	static Mat4 orthographic(
		float left,
		float right,
		float bottom,
		float top,
		float nearPlane,
		float farPlnae
	);

	static Mat4 lookAt(
		float eyeX,
		float eyeY,
		float eyeZ,
		float targetX,
		float targetY,
		float targetZ,
		float upX,
		float upY,
		float upZ
	);

	Mat4 operator*(const Mat4& other) const;
};