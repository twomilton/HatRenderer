#include "Shader.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include <glad/gl.h>

namespace
{
	std::string readFile(const std::string& path)
	{
		std::ifstream file(path);

		if (!file)
		{
			std::cerr << "ERROR: Could not open shader file: "
				<< path << '\n';

			return{};
		}

		std::stringstream buffer;
		buffer << file.rdbuf();

		return buffer.str();
	}
}

Shader::Shader(
	const std::string& vertexPath,
	const std::string& fragmentPath)
{
	const std::string vertexSource = readFile(vertexPath);
	const std::string fragmentSource = readFile(fragmentPath);

	if (vertexSource.empty() || fragmentSource.empty())
	{
		return;
	}

	const char* vertexCode = vertexSource.c_str();
	const char* fragmentCode = fragmentSource.c_str();

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexCode, nullptr);
	glCompileShader(vertexShader);

	int success = 0;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		char infoLog[512];

		glGetShaderInfoLog(
			vertexShader,
			sizeof(infoLog),
			nullptr,
			infoLog
		);

		std::cerr << "ERROR: Vertex shader compilation failed:\n"
			<< infoLog << '\n';

		glDeleteShader(vertexShader);
		return;
	}

	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentCode, nullptr);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		char infoLog[512];

		glGetShaderInfoLog(
			fragmentShader,
			sizeof(infoLog),
			nullptr,
			infoLog
		);

		std::cerr << "ERROR: Fragment shader compilation failed:\n"
			<< infoLog << '\n';

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		return;
	}

	m_program = glCreateProgram();

	glAttachShader(m_program, vertexShader);
	glAttachShader(m_program, fragmentShader);

	glLinkProgram(m_program);

	glGetProgramiv(m_program, GL_LINK_STATUS, &success);

	if (!success)
	{
		char infoLog[512];

		glGetProgramInfoLog(
			m_program,
			sizeof(infoLog),
			nullptr,
			infoLog
		);

		std::cerr << "ERROR: Shader program linking failed:\n"
			<< infoLog << '\n';

		glDeleteProgram(m_program);
		m_program = 0;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}

Shader::~Shader()
{
	if (m_program != 0)
	{
		glDeleteProgram(m_program);
	}
}

void Shader::bind() const
{
	glUseProgram(m_program);
}

