#include "CopiumRenderer/Window.h"
#include "CopiumRenderer/Shader.h"
#include <iostream>

int main(void) {
	Copium::Window window("Test Window");
	Copium::Shader shader("Shaders/shader.vert");

	while(!window.ShouldClose()) {
		window.Render();
		window.Update();
	}

	return 0;
}