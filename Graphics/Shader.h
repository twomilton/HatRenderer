#pragma once

#include <string>

class Shader
{
public:
	Shader(const std::string& vertexPath,
		const std::string& fragmentPath);

	~Shader();

	void bind() const;

private:
	unsigned int m_program = 0;
};