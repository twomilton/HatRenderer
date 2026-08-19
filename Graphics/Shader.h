#pragma once

#include <string>
#include "Math/Mat4.h"

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

private:
	unsigned int m_program = 0;
};