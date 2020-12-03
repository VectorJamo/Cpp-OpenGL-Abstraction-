#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(unsigned int size, const void* data)
{
	glGenBuffers(1, &_bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &_bufferID);
}

void VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
}

void VertexBuffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
