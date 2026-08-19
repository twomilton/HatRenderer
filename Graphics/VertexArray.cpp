#include "VertexArray.h"

#include <cstdint>
#include <glad/gl.h>


VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_id);
}

VertexArray::~VertexArray()
{
	if (m_id != 0)
	{
		glDeleteVertexArrays(1, & m_id);
	}
}

void VertexArray::bind() const
{
	glBindVertexArray(m_id);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}

void VertexArray::addFloatAttribute(
	unsigned int index,
	int componentCount,
	unsigned int stride,
	unsigned int offset
) const
{
	glVertexAttribPointer(
		index,
		componentCount,
		GL_FLOAT,
		GL_FALSE,
		stride,
		reinterpret_cast<const void*>(
			static_cast<uintptr_t>(offset)
		)
	);

	glEnableVertexAttribArray(index);
}

unsigned int VertexArray::id() const
{
	return m_id;
}