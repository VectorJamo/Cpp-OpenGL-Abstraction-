#pragma once

#include <GL/glew.h>

class VertexBuffer
{
private:
	unsigned int _bufferID;

public:
	VertexBuffer(unsigned int size, const void* data);
	~VertexBuffer();

	void bind() const;
	void unbind() const;
};
