// HatRenderer.cpp : Defines the entry point for the application.
//


#include <iostream>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "Graphics/VertexBuffer.h"
#include "Graphics/VertexArray.h"
#include "Graphics/Shader.h"
#include "Graphics/Renderer.h"


// GLFW initialization

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

	int gladVersion = gladLoadGL(glfwGetProcAddress);

	if (gladVersion == 0)
	{
		std::cerr << "ERROR: Failed to initialize GLAD.\n";

		glfwDestroyWindow(window);
		glfwTerminate();

		return -1;
	}

	std::cout << "GLAD initialized.\n";


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


	Renderer renderer;


	// Main app loop.
	while (!glfwWindowShouldClose(window))
	{
		renderer.clear();
		renderer.draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Window clean up.
	glfwDestroyWindow(window);
	glfwTerminate();

	std::cout << "HatRenderer shutting down.\n";
	
	return 0;
}