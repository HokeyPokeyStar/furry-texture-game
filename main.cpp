#include <stdio.h>
#include <GL/glew.h> 
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>


float vertices[] = {
	0.0f, 0.5f,
	0.5f,-0.5f,
	-0.5f,-0.5f
};




std::ifstream t("D:\\princ\\Documents\\Programming\\cmake-glfw-gl3w\\gel.vertex");
std::string vertex((std::istreambuf_iterator<char>(t)),
	std::istreambuf_iterator<char>());

std::ifstream t2("D:\\princ\\Documents\\Programming\\cmake-glfw-gl3w\\gel.fragment");
std::string fragment((std::istreambuf_iterator<char>(t2)),
	std::istreambuf_iterator<char>());

int main(int argc, char * * argv) {

    glfwInit();
	
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    GLFWwindow * window = glfwCreateWindow(800, 600, "GELA GELI GELELELELELZ", nullptr, nullptr); // Windowed 
	
    glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	printf("UR A REAL NOOOOB U DONT SUPPORT MY POTATO");

    printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));

	// GELI GELI ! , WAKE UP , TIME TO CODE , PUT DA CODE HERE OR MAYA , MAGGIE AND FRU FRU WILL EAT YOU
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const char*c_str; glShaderSource(vertexShader, 1, &(c_str = vertex.c_str()), NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &(c_str = fragment.c_str()), NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");

	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(posAttrib);


    while (!glfwWindowShouldClose(window)) {
      glfwSwapBuffers(window);
      glfwPollEvents();
	  glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    return 0;
    glfwTerminate();
}
