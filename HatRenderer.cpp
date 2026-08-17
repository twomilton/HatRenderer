// HatRenderer.cpp : Defines the entry point for the application.
//


#include <iostream>
#include <GLFW/glfw3.h>

void glfwErrorCallback(int error, const char* description)
{
	std::cerr << "GLFW Error " << error << ": "
		<< description << '\n';
}


int main()
{
	glfwSetErrorCallback(glfwErrorCallback);

	std::cout << "Starting HatRenderer...\n";

	if (!glfwInit())
	{
		return -1;
	}

	std::cout << "GLFW initialized. \n";

	// Tell GLFW which version of OpenGL we want.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	std::cout << "Creating OpenGL window...\n";

	// Create the window.
	GLFWwindow* window = glfwCreateWindow(
		1280,
		720,
		"HatRenderer",
		nullptr,
		nullptr
	);

	if (window == nullptr)
	{
		std::cerr << "ERROR: glfwCreateWindow() failed.\n";
		glfwTerminate();
		return -1;
	}

	std::cout << "Window created successfully!\n";

	// Make the OpenGL context current.
	glfwMakeContextCurrent(window);

	const GLubyte* vendor = glGetString(GL_VENDOR);
	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);

	std::cout << "OpenGL Vender:	"
		<< vendor << '\n';

	std::cout << "OpenGL Renderer:	"
		<< renderer << '\n';

	std::cout << "OpenGL Version:	"
		<< version << '\n';


	std::cout << "OpenGL Context created successfully!\n";

	// Main app loop.
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Clean up.
	glfwDestroyWindow(window);
	glfwTerminate();

	std::cout << "HatRenderer shutting down.\n";
	
	return 0;
}