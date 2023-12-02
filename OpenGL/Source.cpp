#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main() 
{

	glfwInit(); // setting up glfw basic configuration 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // setting up max i.e (major) openGl version 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // setting up min openGl version in case of we didnt find the version we required
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	//we're required to create a window object.
	//This window object holds all the windowing data and is required by most of GLFW's other functions.
	GLFWwindow* window = glfwCreateWindow(800, 600, "FirstWindow", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate(); //glfw: terminate, clearing all previously allocated GLFW resources.
		return -1;
	}

	//In GLFW, an OpenGL context is required for rendering graphics. 
	//The OpenGL context represents a state machine that stores all of the OpenGL rendering states and data.
	//It is necessary to create a context and make it current before performing any OpenGL rendering operations.
	glfwMakeContextCurrent(window);

	//We do have to tell GLFW we want to call this function on every window resize by registering it
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//we mentioned that GLAD manages function pointers for OpenGL so we want to initialize GLAD before we call any OpenGL function
	//// glad: load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	
	// render loop
	while (!glfwWindowShouldClose(window))
	{
		// input
		processInput(window);

		// render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		 // Swap front and back buffers
		glfwSwapBuffers(window);
		// Poll for and process events
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}
