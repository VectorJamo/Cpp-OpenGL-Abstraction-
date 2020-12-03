#pragma once
#include <vector>

struct VertexBufferLayout
{
	static std::vector<unsigned int> indices;
	static std::vector<unsigned int> count;

	VertexBufferLayout(unsigned int index, unsigned int dataCount, unsigned int dataType);
};