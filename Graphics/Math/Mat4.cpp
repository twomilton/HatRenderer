#include "Mat4.h"
#include "Vec3.h"

#include <cmath>

#include <iostream>

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

Mat4 Mat4::rotationX(float radians)
{
	Mat4 result = Mat4::identity();

	const float c = std::cos(radians);
	const float s = std::sin(radians);

	result.m[1][1] = c;
	result.m[1][2] = -s;

	result.m[2][1] = s;
	result.m[2][2] = c;

	return result;
}

Mat4 Mat4::rotationY(float radians)
{
	Mat4 result = Mat4::identity();

	const float c = std::cos(radians);
	const float s = std::sin(radians);

	result.m[0][0] = c;
	result.m[0][2] = -s;

	result.m[2][0] = s;
	result.m[2][2] = c;

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
					other.m[row][k] * m[k][column];
			}
		}
	}

	return result;
}

Mat4 Mat4::lookAt(
	float eyeX,
	float eyeY,
	float eyeZ,
	float targetX,
	float targetY,
	float targetZ,
	float upX,
	float upY,
	float upZ)
{
	Vec3 eye{
		eyeX,
		eyeY,
		eyeZ
	};

	Vec3 target{
		targetX,
		targetY,
		targetZ
	};

	Vec3 worldUp{
		upX,
		upY,
		upZ
	};

	Vec3 forward =
		(target - eye).normalized();

	Vec3 right =
		Vec3::cross(
			forward,
			worldUp
		).normalized();

	Vec3 up =
		Vec3::cross(
			right,
			forward
		);

	Mat4 result = Mat4::identity();

	result.m[0][0] = right.x;
	result.m[1][0] = right.y;
	result.m[2][0] = right.z;

	result.m[0][1] = up.x;
	result.m[1][1] = up.y;
	result.m[2][1] = up.z;

	result.m[0][2] = -forward.x;
	result.m[1][2] = -forward.y;
	result.m[2][2] = -forward.z;

	result.m[3][0] =
		-Vec3::dot(right, eye);

	result.m[3][1] =
		-Vec3::dot(up, eye);

	result.m[3][2] =
		Vec3::dot(forward, eye);

	return result;
};

Mat4 Mat4::perspective(
	float fovRadians,
	float aspect,
	float nearPlane,
	float farPlane)
{
	Mat4 result{};

	const float f =
		1.0f / std::tan(fovRadians * 0.5f);

	result.m[0][0] =
		f / aspect;

	result.m[1][1] =
		f;

	result.m[2][2] =
		(farPlane + nearPlane) /
		(nearPlane - farPlane);

	result.m[2][3] =
		-1.0f;

	result.m[3][2] =
		(2.0f * farPlane * nearPlane) /
		(nearPlane - farPlane);

	return result;
}