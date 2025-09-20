#include <iostream>
#include <glad/glad.h>// Include glad to get the OpenGL headers
#include <GLwin.h>  // Include the GLwin header file my GLFW

int main() {
	std::cout << "Starting GLwin! with Modern OpenGL" << std::endl;

	GLwinHello();


	GLwinWindowHint(0, 0); // Not implemented
	GLwinWindowHint(GLWIN_MAXIMIZED, GLWIN_FALSE);
	GLwinWindowHint(GLWIN_RESIZABLE, GLWIN_TRUE); // Default is resizable

	GLWIN_window* window = GLwin_CreateWindow(1200, 600, L"Starting GLwin! with Modern OpenGL");

	if (!window) {
		std::cerr << "Failed to create window!" << std::endl;
		return 1;
	}

	// Set a custom icon (make sure "icon.ico" exists in working directory next to the .exe file)
	GLwinSetWindowIcon(window, L"icon_01.ico");
	GLwinMakeContextCurrent(window);
	int w, h;
	GLwinGetFramebufferSize(window, &w, &h);
	std::cout << "Framebuffer size: " << w << " x " << h << std::endl;

	if (!gladLoadGL()) {
		std::cerr << "Failed to initialize GLAD!" << std::endl;
		return 1;
	}

	glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D


	glGetString(GL_VERSION); // Ensure context is current
	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

	while (!GLwinWindowShouldClose(window)) {
		// Poll and handle events (inputs, window resize, etc.)
		GLwinPollEvents(); // New non-blocking event polling

		if (GLwinGetKey(window, GLWIN_ESCAPE) == GLWIN_PRESS) {
			std::cout << "Escape key pressed, closing window." << std::endl;
			break; // Exit loop to close window
		}
		if (GLwinGetKey(window, GLWIN_SPACE) == GLWIN_PRESS) {
			std::cout << "Space key is being held down." << std::endl;

		}
		// mouse input
		double mx, my;
		GLwinGetCursorPos(window, &mx, &my);
		if (GLwinGetMouseButton(window, GLWIN_MOUSE_BUTTON_LEFT) == GLWIN_PRESS) {
			printf("Mouse Left Button Pressed at (%f, %f)\n", mx, my);
		}


		glClearColor(0.2f, 0.4f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glViewport(0, 0, w, h);



		GLwinSwapBuffers(window);

		GLenum err = glGetError();
		if (err != GL_NO_ERROR) std::cout << "OpenGL error: " << err << std::endl;


	}
	GLwin_DestroyWindow(window); // Clean up and close window
	GLwinTerminate();

	std::wcout << L"Window closed, exiting.\n";
	return 0;
}