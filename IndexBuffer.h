#pragma once

#include "Window.h"

class IndexBuffer
{
private:
	unsigned int ibo;

public:
	IndexBuffer(unsigned int count, const void* data);
	~IndexBuffer();

	void bind() const;
	void unbind() const;

};
