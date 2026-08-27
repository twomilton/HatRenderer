#pragma once

class IndexBuffer
{
public:
	IndexBuffer(
		const unsigned int* indices,
		unsigned int count
	);
	
	~IndexBuffer();

	void bind() const;
	void unbind() const;

	unsigned int getCount() const;

private:
	unsigned int m_rendererID = 0;
	unsigned int m_count = 0;
		
};