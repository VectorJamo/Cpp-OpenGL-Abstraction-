#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

class Window
{
private:
	unsigned int _width, _height;
	const char* _title;
	GLFWwindow* _window;

	bool init();
	
public:
	Window(unsigned int width, unsigned int height, const char* title);
	~Window();

	bool isClosed();
	void clear();
	void swapBuffers();
	void pollEvents();
	void draw();
};
