#include "Mat4.h"

#include <cmath>

Mat4 Mat4::identity()
{
	Mat4 result{};

	result.m[0][0] = 1.0f;
	result.m[1][1] = 1.0f;
	result.m[2][2] = 1.0f;
	result.m[3][3] = 1.0f;

	return result;
}

Mat4 Mat4::translation(float x, float y, float z)
{
	Mat4 result = Mat4::identity();

	result.m[3][0] = x;
	result.m[3][1] = y;
	result.m[3][2] = z;

	return result;
}

Mat4 Mat4::rotationZ(float radians)
{
	Mat4 result = Mat4::identity();

	const float c = std::cos(radians);
	const float s = std::sin(radians);

	result.m[0][0] = c;
	result.m[0][1] = -s;

	result.m[1][0] = s;
	result.m[1][1] = c;

	return result;
}

Mat4 Mat4::orthographic(
	float left,
	float right,
	float bottom,
	float top,
	float nearPlane,
	float farPlane)
{
	Mat4 result{};

	result.m[0][0] =
		2.0f / (right - left);

	result.m[1][1] =
		2.0f / (top - bottom);

	result.m[2][2] =
		-2.0f / (farPlane - nearPlane);

	result.m[3][0] =
		-(right + left) /
		(right - left);

	result.m[3][1] =
		-(top + bottom) /
		(top - bottom);

	result.m[3][2] =
		-(farPlane + nearPlane) /
		(farPlane - nearPlane);

	result.m[3][3] = 1.0f;

	return result;
}

Mat4 Mat4::operator*(const Mat4& other) const
{
	Mat4 result{};

	for (int row = 0; row < 4; ++row)
	{
		for (int column = 0; column < 4; ++column)
		{
			for (int k = 0; k < 4; ++k)
			{
				result.m[row][column] +=
					m[row][k] * other.m[k][column];
			}
		}
	}

	return result;
}