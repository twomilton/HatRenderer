#include "IndexBuffer.h"

#include <glad/gl.h>

IndexBuffer::IndexBuffer(
	const unsigned int* indices,
	unsigned int count)
	: m_count(count)
{
	glGenBuffers(1, &m_rendererID);

	glBindBuffer(
		GL_ELEMENT_ARRAY_BUFFER,
		m_rendererID
	);

	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER,
		count * sizeof(unsigned int),
		indices,
		GL_STATIC_DRAW
	);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &m_rendererID);
}

void IndexBuffer::bind() const
{
	glBindBuffer(
		GL_ELEMENT_ARRAY_BUFFER,
		m_rendererID
	);
}

unsigned int IndexBuffer::getCount() const
{
	return m_count;
}