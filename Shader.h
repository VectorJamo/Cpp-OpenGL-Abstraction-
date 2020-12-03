#pragma once

#include <iostream>
#include <string>

class Shader
{
private:
	unsigned int shaderProgram;
	const char* VertexShaderCode;
	const char* FragmentShaderCode;

	std::string loadShader(std::string code);
	unsigned int compileShader(unsigned int type, const char* code);
	unsigned int createShaderProgram();
	
public:
	Shader(std::string vertexShaderPath, std::string fragmentShaderPath);
	~Shader();

	void setUniform4f(const char* uniformName, float f1, float f2, float f3, float f4);
	void setUniform1i(const char* uniformName, int i1);
	void bind() const;
	void unbind() const;
};
