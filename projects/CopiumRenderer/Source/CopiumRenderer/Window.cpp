#include "Window.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Callbacks
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

namespace Copium {
	Window::Window(const char* title, int width, int height) : window(nullptr), title(title), width(width), height(height) {
		if(!glfwInit())
			std::cout << "GLFW initialization failed!" << std::endl;

		glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
		//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL 3.3
		//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Not legacy OpenGL

		window = glfwCreateWindow(width, height, title, NULL, NULL);

		if(!window) {
			glfwTerminate();
			std::cout << "Window initialization failed!" << std::endl;
		}

		glfwMakeContextCurrent(window);

		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		glewExperimental = GL_TRUE;
		if(glewInit() != GLEW_OK) {
			std::cout << "GLEW initialization failed!" << std::endl;
		}

		glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE); // Guarantees that a keypress is registered when pressed

		glViewport(0, 0, width, height); // Tell OpenGL how big our window is
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

/* A GLFW callback function that updates the OpenGL viewport when the GLFW window is resized */
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width/2, height);
}
