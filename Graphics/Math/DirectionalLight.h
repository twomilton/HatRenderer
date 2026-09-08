#pragma once

#include "Vec3.h"

struct DirectionalLight
{
	Vec3 direction;
	Vec3 color;

	float intensity;
};