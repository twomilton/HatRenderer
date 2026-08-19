#include "Mat4.h"

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