#include "Window.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Copium {
	Window::Window(const char* title, int width, int height) : window(nullptr), title(title), width(width), height(height) {
		glewExperimental = GL_TRUE;
		if(!glfwInit())
			std::cout << "GLFW initialization failed!" << std::endl;

		window = glfwCreateWindow(width, height, title, NULL, NULL);

		if(!window) {
			glfwTerminate();
			std::cout << "Window initialization failed!" << std::endl;
		}

		glfwMakeContextCurrent(window);

		if(glewInit() != GLEW_OK) {
			std::cout << "GLEW initialization failed!" << std::endl;
		}
	}

	void Window::Render() {
		glClear(GL_COLOR_BUFFER_BIT);
	
		glBegin(GL_TRIANGLES);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f(0.f, 0.5f);
			glVertex2f(0.5f, -0.5f);
		glEnd();
	
		/* Swap front and back buffers */
		glfwSwapBuffers(window);
	}

	void Window::Update() {
		glfwPollEvents();
	}

	bool Window::ShouldClose() {
		return glfwWindowShouldClose(window);
	}

}