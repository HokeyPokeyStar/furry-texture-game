#include <stdio.h>
#include <GL/glew.h> 
#include <GLFW/glfw3.h>


int main(int argc, char * * argv) {
    glfwInit();
	
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow * window = glfwCreateWindow(800, 600, "GELA GELI GELELELELELZ", nullptr, nullptr); // Windowed 
	
    glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);	

	printf("%u\n", vertexBuffer);

	printf("UR A REAL NOOOOB U DONT SUPPORT MY POTATO");

    printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));

    while (!glfwWindowShouldClose(window)) {
      glfwSwapBuffers(window);
      glfwPollEvents();
    }

    return 0;
    glfwTerminate();
}
