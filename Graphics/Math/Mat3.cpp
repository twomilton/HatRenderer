#include "Mat3.h"

Mat3 Mat3::identity()
{
	Mat3 result{};

	result.m[0][0] = 1.0f;
	result.m[1][1] = 1.0f;
	result.m[2][2] = 1.0f;

	return result;
}

Mat3 Mat3::transpose() const
{
	Mat3 result{};

	for (int row = 0; row < 3; ++row)
	{
		for (int column = 0; column < 3; ++column)
		{
			result.m[row][column] =
				m[column][row];
		}
	}

	return result;
}

Mat3 Mat3::inverse() const
{
	Mat3 result{};

	const float determinant =
		m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
		- m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
		+ m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);

	if (determinant == 0.0f)
	{
		return Mat3::identity();
	}

	const float inverseDeterminant =
		1.0f / determinant;

	result.m[0][0] =
		(m[1][1] * m[2][2] -
		m[1][2] * m[2][1])*
		inverseDeterminant;

	result.m[0][1] =
		(m[0][2] * m[2][1] -
		m[0][1] * m[2][2])*
		inverseDeterminant;

	result.m[0][2] =
		(m[0][1] * m[1][2] -
		m[0][2] * m[1][1])*
		inverseDeterminant;

	result.m[1][0] =
		(m[1][2] * m[2][0] -
		m[1][0] * m[2][2])*
		inverseDeterminant;

	result.m[1][1] =
		(m[0][0] * m[2][2] -
		m[0][2] * m[2][0])*
		inverseDeterminant;

	result.m[1][2] =
		(m[0][2] * m[1][0] -
		m[0][2] * m[1][2])*
		inverseDeterminant;

	result.m[2][0] =
		(m[1][0] * m[2][1] -
		m[1][1] * m[2][0])*
		inverseDeterminant;

	result.m[2][1] =
		(m[0][1] * m[2][0] -
		m[0][0] * m[2][1])*
		inverseDeterminant;

	result.m[2][2] =
		(m[0][0] * m[1][1] -
		m[0][1] * m[1][0])*
		inverseDeterminant;

	return result;
}