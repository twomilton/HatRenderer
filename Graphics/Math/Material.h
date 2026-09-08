#pragma once

#include "Vec3.h"

struct Material
{
	Vec3 ambient;
	Vec3 diffuse;
	Vec3 specular;

	float shininess;
};