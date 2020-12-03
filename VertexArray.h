#pragma once

#include "Window.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"

class VertexArrayObject
{
private:
	unsigned int VAO;
	unsigned int getDataCountPerVertex();
	unsigned int getDataOffest();

public:
	VertexArrayObject(VertexBuffer& vb);
	~VertexArrayObject();

	void bind() const;
	void unbind() const;

};
