#include "CopiumRenderer\Window.h"
#include <iostream>

int main(void) {
	Copium::Window window("Test Window");

	while(!window.ShouldClose()) {
		window.Render();
		window.Update();
	}

	return 0;
}