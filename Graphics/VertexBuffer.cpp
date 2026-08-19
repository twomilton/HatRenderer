#include "VertexBuffer.h"

#include <glad/gl.h>

VertexBuffer::VertexBuffer(const float* data, unsigned int size)
{
	glGenBuffers(1, &m_id);
	glBindBuffer(GL_ARRAY_BUFFER, m_id);

	glBufferData(
		GL_ARRAY_BUFFER,
		size,
		data,
		GL_STATIC_DRAW
	);
}

VertexBuffer::~VertexBuffer()
{
	if (m_id != 0)
	{
		glDeleteBuffers(1, &m_id);
	}
}

void VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void VertexBuffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

unsigned int VertexBuffer::id() const
{
	return m_id;
}