#include "Renderer.h"
#include "Math/Mat4.h"

#include <glad/gl.h>

#include <iostream>

namespace
{
	const float vertices[] =
	{
		// Position			// Color
		-0.5f, -0.5f, 0.0f,	 1.0f, 0.0f, 0.0f,	//Red
		 0.5f, -0.5f, 0.0f,	 0.0f, 1.0f, 0.0f,	//Green
		 0.0f, 0.5f, -1.0f,	 0.0f, 0.0f, 1.0f	//Blue
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
		3,
		6 * sizeof(float),
		0
	);

	m_vertexArray.addFloatAttribute(
		1,
		3,
		6 * sizeof(float),
		3 * sizeof(float)
	);
}

void Renderer::clear() const
{
	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
	glClear(
		GL_COLOR_BUFFER_BIT |
		GL_DEPTH_BUFFER_BIT
	);
}

void Renderer::draw( 
	const IndexBuffer& indexBuffer 
) const
{
	const float aspectRatio =
		static_cast<float>(m_viewportWidth) /
		static_cast<float>(m_viewportHeight);

	Mat4 projection =
		//Mat4::orthographic(
		//	-aspectRatio,
		//	aspectRatio,
		//	-1.0f,
		//	1.0f,
		//	-10.0f,
		//	10.0f
		//);

		Mat4::perspective(
			45.0f * 3.14159265f / 180.0f,
			aspectRatio,
			0.1f,
			100.0f
		);

	Mat4 translation =
		Mat4::translation(
			0.0f,
			0.0f,
			0.0f
		);

	Mat4 rotation =
		Mat4::rotationY(0.7f);

	Mat4 view =
		Mat4::lookAt(
			0.0f, 0.0f, 3.0f,
			0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f
		);

	Mat4 transform =
		//projection * view;
		//projection * rotation;
		//projection * view * translation;
		projection * view * rotation;

	m_shader.bind();

	m_shader.setMat4(
		"uTransform",
		transform
	);

	m_vertexArray.bind();
	indexBuffer.bind();

	//std::cout << "Index count: "
	//	<< indexBuffer.getCount()
	//	<< '\n';

	//std::cout << "VAO: "
	//	<< m_vertexArray.id()
	//	<< '\n';
			

	//glDrawElements(GL_TRIANGLES, 0, 3);
	glDrawElements(
		GL_TRIANGLES,
		indexBuffer.getCount(),
		GL_UNSIGNED_INT,
		nullptr
	);
}

void Renderer::setViewportSize(int width, int height)
{
	m_viewportWidth = width;
	m_viewportHeight = height;
}


