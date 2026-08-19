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

private:
	VertexBuffer m_vertexBuffer;
	VertexArray m_vertexArray;
	Shader m_shader;
};