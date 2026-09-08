#pragma once

struct Mat3
{
	float m[3][3]{};

	static Mat3 identity();

	Mat3 transpose() const;
	Mat3 inverse() const;
};