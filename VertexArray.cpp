#include "VertexArray.h"

std::vector<unsigned int> VertexBufferLayout::indices;
std::vector<unsigned int> VertexBufferLayout::count;

unsigned int VertexArrayObject::getDataOffest()
{
	unsigned int temp = VertexBufferLayout::indices.size() - 2;
	unsigned int dataCountBefore = 0;
	while (temp != -1)
	{
		dataCountBefore += VertexBufferLayout::count[temp];
		temp--;
	}

	return dataCountBefore * sizeof(float);
}

unsigned int VertexArrayObject::getDataCountPerVertex()
{
	unsigned int dataCountPerVertex = 0;
	for (int i = 0; i < VertexBufferLayout::indices.size(); i++)
	{
		dataCountPerVertex += VertexBufferLayout::count[i];
	}

	return dataCountPerVertex;
}
VertexArrayObject::VertexArrayObject(VertexBuffer& vb)
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	vb.bind();

	for (int i = 0; i < VertexBufferLayout::indices.size(); i++)
	{
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, VertexBufferLayout::count[i], GL_FLOAT, GL_FALSE, getDataCountPerVertex() * sizeof(float), (void*)(i == 0 ? 0 : getDataOffest()));
	}
}

VertexArrayObject::~VertexArrayObject()
{
	glDeleteVertexArrays(1, &VAO);
}

void VertexArrayObject::bind() const
{
	glBindVertexArray(VAO);
}

void VertexArrayObject::unbind() const
{
	glBindVertexArray(0);
}
