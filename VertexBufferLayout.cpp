#include "VertexBufferLayout.h"

#include <GL/glew.h>
#include <iostream>

VertexBufferLayout::VertexBufferLayout(unsigned int index, unsigned int dataCount, unsigned int dataType)
{
	indices.push_back(index);
	count.push_back(dataCount);
}

