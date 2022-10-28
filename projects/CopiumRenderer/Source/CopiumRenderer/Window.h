#pragma once
#include<string>

class GLFWwindow;

namespace Copium {

class Window {
private:
	GLFWwindow* window;
	std::string title;
	int width, height;
	unsigned int vbo;

public:
	Window(const char* title, int width = 1920, int height = 1080);

	void Render();
	void Update();
	void ProcessInput();

	bool ShouldClose();
};

}