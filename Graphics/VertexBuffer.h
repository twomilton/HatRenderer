#pragma once

class VertexBuffer
{
public:
	VertexBuffer(const float* data, unsigned int size);
	~VertexBuffer();

	void bind() const;
	void unbind() const;

	unsigned int id() const;

private:
	unsigned int m_id = 0;
};