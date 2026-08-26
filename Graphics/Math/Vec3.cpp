#include "Vec3.h"

#include <cmath>

Vec3 Vec3::operator+(const Vec3& other) const
{
	return {
		x + other.x,
		y + other.y,
		z + other.z
	};
}

Vec3 Vec3::operator-(const Vec3& other) const
{
	return {
		x - other.x,
		y - other.y,
		z - other.z
	};
}

Vec3 Vec3::operator*(float scalar) const
{
	return {
		x * scalar,
		y * scalar,
		z * scalar
	};
}

float Vec3::dot(
	const Vec3& a,
	const Vec3& b)
{
	return
		a.x * b.x +
		a.y * b.y +
		a.z * b.z;
}

Vec3 Vec3::cross(
	const Vec3& a,
	const Vec3& b)
{
	return {
		a.y * a.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	};
}

Vec3 Vec3::normalized() const
{
	const float length =
		std::sqrt(
			x * x +
			y * y +
			z * z
		);

	if (length == 0.0f)
	{
		return { 0.0f, 0.0f, 0.0f };
	}

	return {
		x / length,
		y / length,
		z / length
	};
}