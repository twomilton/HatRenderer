// HatRenderer.cpp : Defines the entry point for the application.
//


#include <iostream>

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "Graphics/Shader.h"



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

	float vertices[] =
	{
		// Position		// Color
		-0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	//Red
		 0.5f, -0.5f,	0.0f, 1.0f, 0.0f,	//Green
		 0.0f, 0.5f,	0.0f, 0.0f, 1.0f	//Blue
	};

	unsigned int VBO;

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(
		GL_ARRAY_BUFFER,
		sizeof(vertices),
		vertices,
		GL_STATIC_DRAW
	);

	unsigned int VAO;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glVertexAttribPointer(
		0,
		2,
		GL_FLOAT,
		GL_FALSE,
		5 * sizeof(float),
		(void*)0
	);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(
		1,
		3,
		GL_FLOAT,
		GL_FALSE,
		5 * sizeof(float),
		(void*)(2 * sizeof(float))
	);

	glEnableVertexAttribArray(1);


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

	Shader triangleShader(
		HATRENDERER_SHADER_DIR "/triangle.vert",
		HATRENDERER_SHADER_DIR "/triangle.frag"
	);

	// Main app loop.
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		triangleShader.bind();
		glBindVertexArray(VAO);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Clean up.
	glfwDestroyWindow(window);
	glfwTerminate();

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	std::cout << "HatRenderer shutting down.\n";
	
	return 0;
}