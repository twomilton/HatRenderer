#pragma once

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void bind() const;
	void unbind() const;

	void addFloatAttribute(
		unsigned int index,
		int componentCount,
		unsigned int stride,
		unsigned int offset
	) const;

	unsigned int id() const;

private:
	unsigned int m_id = 0;
};