// HatRenderer.cpp : Defines the entry point for the application.
//


#include <iostream>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "Graphics/VertexBuffer.h"
#include "Graphics/VertexArray.h"
#include "Graphics/Shader.h"
#include "Graphics/Renderer.h"

#include "Graphics/IndexBuffer.h"


// GLFW initialization

void glfwErrorCallback(int error, const char* description)
{
	std::cerr << "GLFW Error " << error << ": "
		<< description << '\n';
}

// callback to resize window
void framebufferResizeCallback(
	GLFWwindow* window,
	int width,
	int height)
{
	glViewport(0, 0, width, height);

	Renderer* renderer =
		static_cast<Renderer*>(
			glfwGetWindowUserPointer(window)
			);

	if (renderer != nullptr)
	{
		renderer->setViewportSize(
			width,
			height
		);
	}
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

	glfwSetFramebufferSizeCallback(
		window,
		framebufferResizeCallback
	);

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
	glEnable(GL_DEPTH_TEST);

	const GLubyte* vendor = glGetString(GL_VENDOR);
	const GLubyte* rendererName = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);

	std::cout << "OpenGL Vendor:	"
		<< vendor << '\n';

	std::cout << "OpenGL Renderer:	"
		<< rendererName << '\n';

	std::cout << "OpenGL Version:	"
		<< version << '\n';


	std::cout << "OpenGL Context created successfully!\n";


	Renderer renderer;

	glfwSetWindowUserPointer(
		window,
		&renderer
	);

	int framebufferWidth;
	int framebufferHeight;

	glfwGetFramebufferSize(
		window,
		&framebufferWidth,
		&framebufferHeight
	);

	glViewport(
		0,
		0,
		framebufferWidth,
		framebufferHeight
	);

	renderer.setViewportSize(
		framebufferWidth,
		framebufferHeight
	);

	unsigned int indices[] =
	{
		// Front
		0, 1, 2,
		2, 3, 0,

		// Back
		4, 6, 5,
		6, 4, 7,

		// Left
		8, 9, 10,
		10, 11, 8,

		// Right 
		12, 13, 14,
		14, 15, 12,

		// Top
		16, 17, 18,
		18, 19, 16,

		// Bottom
		29, 21, 22,
		22, 23, 20
	};

	IndexBuffer indexBuffer(
		indices,
		sizeof(indices) / sizeof(unsigned int)
	);

	// Main app loop.
	while (!glfwWindowShouldClose(window))
	{
		renderer.clear();
		renderer.draw(indexBuffer);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Window clean up.
	glfwDestroyWindow(window);
	glfwTerminate();

	std::cout << "HatRenderer shutting down.\n";
	
	return 0;
}