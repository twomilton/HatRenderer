#pragma once

struct Vec3 {
	float x;
	float y;
	float z;

	Vec3 operator+(const Vec3& other) const;
	Vec3 operator-(const Vec3& other) const;
	Vec3 operator*(float scalar) const;

	static float dot(
		const Vec3& a,
		const Vec3& b
	);

	static Vec3 cross(
		const Vec3& a,
		const Vec3& b
	);

	Vec3 normalized() const;
};



