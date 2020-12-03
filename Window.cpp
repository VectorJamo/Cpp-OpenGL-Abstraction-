#include "Window.h"
#include <iostream>

Window::Window(unsigned int width, unsigned int height, const char* title)
{
	_width = width;
	_height = height;
	_title = title;

	if (!init())
		return;
}

Window::~Window()
{
	glfwTerminate();
}

bool Window::init()
{
	if (!glfwInit())
	{
		std::cout << "Failed to init GLFW!" << std::endl;
		return false;
	}
	_window = glfwCreateWindow(_width, _height, _title, NULL, NULL);
	if (!_window)
	{
		std::cout << "Failed to init Window!" << std::endl;
		return false;
	}

	glfwMakeContextCurrent(_window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW init failed!" << std::endl;
		return false;
	}

	std::cout << glGetString(GL_VERSION) << std::endl;
	glClearColor(0.3f, 0.3f, 0.7f, 1.0f);
	return true;
}


void Window::clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::swapBuffers()
{
	glfwSwapBuffers(_window);
}

void Window::pollEvents()
{
	glfwPollEvents();
}

void Window::draw()
{
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
}

bool Window::isClosed()
{
	return glfwWindowShouldClose(_window);
}