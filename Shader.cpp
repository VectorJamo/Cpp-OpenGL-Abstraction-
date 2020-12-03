#include "Shader.h"

#include <GL/glew.h>
#include <fstream>

Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath)
{
	std::string vsCode = loadShader(vertexShaderPath);
	VertexShaderCode = vsCode.c_str();

	std::string fsCode = loadShader(fragmentShaderPath);
	FragmentShaderCode = fsCode.c_str();

	shaderProgram = createShaderProgram();
	
}

Shader::~Shader()
{
	glUseProgram(0);
}

std::string Shader::loadShader(std::string code)
{
	std::ifstream stream(code);
	std::string line;
	std::string shaderCode;

	while (std::getline(stream, line))
	{
		shaderCode += line + "\n";
	}

	return shaderCode;
}

unsigned int Shader::compileShader(unsigned int type, const char* code)
{
	unsigned int shader = glCreateShader(type);
	glShaderSource(shader, 1, &code, 0);
	glCompileShader(shader);

	int result;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

	if (result != GL_TRUE)
	{
		int length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

		char* message = (char*)alloca(sizeof(char) * length);
		glGetShaderInfoLog(shader, length, &length, message);

		std::cout << "|| Shader Error ||" << std::endl;
		std::cout << "Shader Type: " <<  (type == GL_VERTEX_SHADER ? "Vertex Shader" : "Fragment Shader") << std::endl;
		std::cout << message << std::endl;

		return 0;
	}
	return shader;
}

unsigned int Shader::createShaderProgram()
{
	unsigned int program = glCreateProgram();
	unsigned int vs = compileShader(GL_VERTEX_SHADER, VertexShaderCode);
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, FragmentShaderCode);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	return program;
}

void Shader::setUniform4f(const char* uniformName, float f1, float f2, float f3, float f4)
{
	unsigned int uniLocation = glGetUniformLocation(shaderProgram, uniformName);
	glUniform4f(uniLocation, f1, f2, f3, f4);
}

void Shader::setUniform1i(const char* uniformName, int i1)
{
	unsigned int uniLocation = glGetUniformLocation(shaderProgram, uniformName);
	glUniform1i(uniLocation, i1);
}
void Shader::bind() const
{
	glUseProgram(shaderProgram);
}

void Shader::unbind() const
{
	glUseProgram(0);
}
