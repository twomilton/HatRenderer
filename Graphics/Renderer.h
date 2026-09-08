#pragma once

#include <memory>

#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Math/Material.h"
#include "Math/DirectionalLight.h"

class Renderer
{
public:
	Renderer();

	void clear() const;
	void draw(
		const IndexBuffer& indexBuffer
	) const;

	void setViewportSize(int width, int height);

private:
	VertexBuffer m_vertexBuffer;
	VertexArray m_vertexArray;
	Shader m_shader;

	int m_viewportWidth = 1280;
	int m_viewportHeight = 720;

	Material m_material;
	DirectionalLight m_light;

};