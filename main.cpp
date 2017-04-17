#include <stdio.h>
#include <GL/glew.h> 
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

//float vertices[] = {
//	-0.5f,  0.5f, 1.0f, 0.0f, 0.0f, // Top-left
//	0.5f,  0.5f, 0.0f, 1.0f, 0.0f, // Top-right
//	0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // Bottom-right
//	-0.5f, -0.5f, 1.0f, 1.0f, 1.0f  // Bottom-left
//};

float vertices[] = {
	0.0f,  0.5f, 1.0f, 0.0f, 0.0f, // Vertex 1: Red
	0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // Vertex 2: Green
	-0.5f, -0.5f, 0.0f, 0.0f, 1.0f  // Vertex 3: Blue
};

GLuint elements[] = {
	0, 1, 2,
	2,3,0
};


GLuint LoadShader(const char *vertex_path, const char *fragment_path) {
	GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);

	// Read shaders
	std::ifstream in(vertex_path);
	std::string vertShaderStr((std::istreambuf_iterator<char>(in)),
		std::istreambuf_iterator<char>());
	in = std::ifstream(fragment_path);
	std::string fragShaderStr((std::istreambuf_iterator<char>(in)),
		std::istreambuf_iterator<char>());
	const char *vertShaderSrc = vertShaderStr.c_str();
	const char *fragShaderSrc = fragShaderStr.c_str();

	GLint result = GL_FALSE;
	int logLength;

	// Compile vertex shader
	std::cout << "Compiling vertex shader." << std::endl;
	glShaderSource(vertShader, 1, &vertShaderSrc, NULL);
	glCompileShader(vertShader);

	// Check vertex shader
	glGetShaderiv(vertShader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> vertShaderError((logLength > 1) ? logLength : 1);
	glGetShaderInfoLog(vertShader, logLength, NULL, &vertShaderError[0]);
	std::cout << &vertShaderError[0] << std::endl;

	// Compile fragment shader
	std::cout << "Compiling fragment shader." << std::endl;
	glShaderSource(fragShader, 1, &fragShaderSrc, NULL);
	glCompileShader(fragShader);

	// Check fragment shader
	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> fragShaderError((logLength > 1) ? logLength : 1);
	glGetShaderInfoLog(fragShader, logLength, NULL, &fragShaderError[0]);
	std::cout << &fragShaderError[0] << std::endl;

	std::cout << "Linking program" << std::endl;
	GLuint program = glCreateProgram();
	glAttachShader(program, vertShader);
	glAttachShader(program, fragShader);
	glLinkProgram(program);

	glGetProgramiv(program, GL_LINK_STATUS, &result);
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
	std::vector<char> programError((logLength > 1) ? logLength : 1);
	glGetProgramInfoLog(program, logLength, NULL, &programError[0]);
	std::cout << &programError[0] << std::endl;

	glDeleteShader(vertShader);
	glDeleteShader(fragShader);

	return program;
}

int main(int argc, char * * argv) {
	auto t_start = std::chrono::high_resolution_clock::now();
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
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

	GLuint ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		sizeof(elements), elements, GL_STATIC_DRAW);

	GLuint shaderProgram = LoadShader("D:\\princ\\Documents\\Programming\\cmake-glfw-gl3w\\gel.vert", "D:\\princ\\Documents\\Programming\\cmake-glfw-gl3w\\gel.frag");
	glUseProgram(shaderProgram);
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5*sizeof(float), 0);

	GLint atColor = glGetAttribLocation(shaderProgram, "color");
	glEnableVertexAttribArray(atColor);
	glVertexAttribPointer(atColor, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
	 
	
	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    return 0;
    glfwTerminate();
}

