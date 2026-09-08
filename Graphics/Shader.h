#pragma once

#include <string>
#include "Math/Mat4.h"
#include "Math/Mat3.h"
#include "Math/Vec3.h"

class Shader
{
public:
	Shader(
		const std::string& vertexPath,
		const std::string& fragmentPath);

	~Shader();

	void bind() const;

	void setMat4(
		const char* name, 
		const Mat4& matrix
	) const;

	void setMat3(
		const char* name,
		const Mat3& matrix
	) const;

	void setVec3(
		const char* name,
		const Vec3& value
	) const;

	void setFloat(
		const char* name,
		float value
	) const;

private:
	unsigned int m_program = 0;
};