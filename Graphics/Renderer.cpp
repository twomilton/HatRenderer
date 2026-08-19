#include "Renderer.h"

#include <glad/gl.h>

namespace
{
	const float vertices[] =
	{
		// Position		// Color
		-0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	//Red
		 0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	//Green
		 0.0f, 0.5f,	0.0f, 0.0f, 1.0f	//Blue
	};
}

Renderer::Renderer()
	: m_vertexBuffer(vertices, sizeof(vertices))
	, m_vertexArray()
	, m_shader(
		HATRENDERER_SHADER_DIR "/triangle.vert",
		HATRENDERER_SHADER_DIR "/triangle.frag")
{
	m_vertexArray.bind();
	m_vertexBuffer.bind();

	m_vertexArray.addFloatAttribute(
		0,
		2,
		5 * sizeof(float),
		0
	);

	m_vertexArray.addFloatAttribute(
		1,
		3,
		5 * sizeof(float),
		2 * sizeof(float)
	);
}

void Renderer::clear() const
{
	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw() const
{
	m_shader.bind();
	m_vertexArray.bind();

	glDrawArrays(GL_TRIANGLES, 0, 3);
}

