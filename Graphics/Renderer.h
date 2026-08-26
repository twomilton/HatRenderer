#pragma once

#include <memory>

#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"

class Renderer
{
public:
	Renderer();

	void clear() const;
	void draw() const;

	void setViewportSize(int width, int height);

private:
	VertexBuffer m_vertexBuffer;
	VertexArray m_vertexArray;
	Shader m_shader;

	int m_viewportWidth = 1280;
	int m_viewportHeight = 720;

};