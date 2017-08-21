#include <iostream>
#include <cstdint>
#include <vector>
#include <epoxy/gl.h>
#include <GLFW/glfw3.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <cmath>

void cinEnder(std::atomic<bool> *run, std::condition_variable *cv)
{
	char dump;
	std::cin >> dump;
	*run = false;
	cv->notify_one();
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	std::cout << "Window resized to " << width << " by " << height << '\n';
	glViewport(0,0,width,height);
}

void process_input(GLFWwindow* window)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window,true);
	}
}

class Renderer
{
public:
	Renderer() : vertices {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f },
		theta1 {0.0}, theta2 {2 * 3.1415926535 / 3},
		theta3 {4 * 3.1415926535 / 3}, distToVertex {0.4},
		rectangleVertices {
		-0.9f, 0.9f, 0.0f,
		-0.9f, 0.6f, 0.0f,
		-0.6f, 0.9f, 0.0f,
		-0.6f, 0.6f, 0.0f},
		rectangleIndices {
		0, 1, 3, 1, 2, 3},
		pi { 3.1415926535897 },
		circleIncrement { 2 * 3.1415926535897 / (179 * 3) },
		numCircVertices { 9 * 180 }
	{
		glGenBuffers(1,&VBO);
		// Initialize variables for use with shader stuff
		char *vertexShaderStr {"#version 330 core \nlayout(location = 0) in vec3 aPos;\nvoid main(){gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);}"};
		unsigned int vertexShaderId;
		char *fragmentShaderStr {"#version 330 core \nout vec4 FragColor;\nvoid main(){FragColor = vec4(0.0f,0.0f,0.0f,1.0f);}"};
		unsigned int fragmentShaderId;
		// Vertex Shader Stuff
		vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShaderId,1,&vertexShaderStr,NULL);
		glCompileShader(vertexShaderId);
		// Make sure Vertex Shader compiled properly
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShaderId,GL_COMPILE_STATUS,&success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShaderId,512,NULL,infoLog);
			std::cout << "ERROR::SHADER_VERTEX::COMPILATION_FAILED\n" << infoLog << '\n';
		}
		// Fragment Shader Stuff
		fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShaderId,1,&fragmentShaderStr,NULL);
		glCompileShader(fragmentShaderId);
		// Make sure Fragment Shader compiled properly
		char infoLog2[512];
		glGetShaderiv(fragmentShaderId,GL_COMPILE_STATUS,&success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShaderId,512,NULL,infoLog2);
			std::cout << "ERROR::SHADER_FRAG::COMPILATION_FAILED\n" << infoLog2 << '\n';
		}
		// Create and link the shader program
		shaderProgramId = glCreateProgram();
		glAttachShader(shaderProgramId,vertexShaderId);
		glAttachShader(shaderProgramId,fragmentShaderId);
		glLinkProgram(shaderProgramId);
		char infoLog3[512];
		glGetProgramiv(shaderProgramId,GL_LINK_STATUS,&success);
		// Make sure linking was successful
		if (!success)
		{
			glGetProgramInfoLog(shaderProgramId,512,NULL,infoLog3);
			std::cout << "ERROR::LINKER::LINKING_FAILED\n" << infoLog3 << '\n';
		}
		// Delete the unneeded shader objects
		glDeleteShader(vertexShaderId);
		glDeleteShader(fragmentShaderId);
		// Create VAO
		glGenVertexArrays(1,&VAO);
		// Create EBO
		glGenBuffers(1,&EBO);
		// Create a second VAO and VBO for the rectangle
		glGenBuffers(1,&VBORect);
		glGenVertexArrays(1,&VAORect);
		// Create a thrid VAO and VBO for the circle
		glGenBuffers(1,&VBOCircle);
		glGenVertexArrays(1,&VAOCircle);
		// Fill circle vertices array
		float circTheta[3] {0.0f, 2.0f * pi / 3.0f, 4.0f * pi / 3.0f};
		float circleXCoord {0.6};
		float circleYCoord {-0.6};
		float circRadius {0.2};
		for (int i {0}; i < 9 * 180; i += 9)
		{
			for (int ii {0}; ii < 3; ++ii)
			{
				circleVertices[i + 3 * ii] = circleXCoord + cos(circTheta[ii]) * circRadius;
				circleVertices[i + 1 + 3 * ii] = circleYCoord + sin(circTheta[ii]) * circRadius;
				circleVertices[i + 2 + 3 * ii] = 0;
				updateTheta(circTheta[ii],circleIncrement);
			}
		}
		glBindVertexArray(VAOCircle);
		glBindBuffer(GL_ARRAY_BUFFER,VBOCircle);
		glBufferData(GL_ARRAY_BUFFER,sizeof(circleVertices),circleVertices,GL_STATIC_DRAW);
		// Create a glVertexAttrib pointer
		glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3 * sizeof(float),(void*)0);
		glEnableVertexAttribArray(0);
		// Bins Element object buffer and stores indices
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER,0);
	}
	// Updates theta values
	static void updateTheta(float &thetaVal, float incrementVal)
	{
		thetaVal += incrementVal;
		if (thetaVal > 2.0f * 3.14159265f - 0.01f)
		{
			thetaVal = 0.0f;
		}
	}
	// Sets up the render loop for drawing a triangle
	void renderTriangleSetup()
	{
		// Calculate position of vertex 1
		vertices[0] = cos(theta1) * distToVertex;
		vertices[1] = sin(theta1) * distToVertex;
		// Calculate position of vertex 2
		vertices[3] = cos(theta2) * distToVertex;
		vertices[4] = sin(theta2) * distToVertex;
		// Calculate position of vertex 3
		vertices[6] = cos(theta3) * distToVertex;
		vertices[7] = sin(theta3) * distToVertex;
		// Update theta values for next iteration
		updateTheta(theta1,0.05f);
		updateTheta(theta2,0.05f);
		updateTheta(theta3,0.05f);
		// Binds vertex and array and stores new verticies
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STREAM_DRAW);
		// Create a glVertexAttrib pointer
		glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3 * sizeof(float),(void*)0);
		glEnableVertexAttribArray(0);
		// Bins Element object buffer and stores indices
		glBindBuffer(GL_ARRAY_BUFFER,0);
		glBindVertexArray(0);
		glBindVertexArray(VAORect);
		glBindBuffer(GL_ARRAY_BUFFER,VBORect);
		glBufferData(GL_ARRAY_BUFFER,sizeof(rectangleVertices),rectangleVertices,
			GL_STREAM_DRAW);
		// Create a glVertexAttrib pointer for this vertex array object
		glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3 * sizeof(float),(void*)0);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(rectangleIndices), rectangleIndices,
			GL_STREAM_DRAW);
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER,0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
	}
	// Renders a triangle on the opengl window (2-D)
	void renderTriangle()
	{
		// Make openGL use this shader program
		glUseProgram(shaderProgramId);
		glBindVertexArray(VAO);
		// Draw the triangle
		glDrawArrays(GL_TRIANGLES,0,3);
		// Bind and store different vertex data
		glBindBuffer(GL_ARRAY_BUFFER,0);
		glBindVertexArray(0);
	}
	// Renders the rectangle
	void renderRectangle()
	{
		glUseProgram(shaderProgramId);
		glBindVertexArray(VAORect);
		glBindBuffer(GL_ARRAY_BUFFER, VBORect);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
		// Draw the rectangle
		glDrawElements(GL_TRIANGLES,6, GL_UNSIGNED_INT, 0);
		glBindBuffer(GL_ARRAY_BUFFER,0);
		glBindVertexArray(0);
	}
	void renderCircle()
	{
		glUseProgram(shaderProgramId);
		// Bind correct vertex array
		glBindVertexArray(VAOCircle);
		glBindBuffer(GL_ARRAY_BUFFER, VBOCircle);
		// Draw the circle
		glDrawArrays(GL_TRIANGLES,0,numCircVertices);
		// Unbind these buffers
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER,0);
	}
private:
	float vertices[9];
	float theta1;
	float theta2;
	float theta3;
	float distToVertex;
	float rectangleVertices[12];
	unsigned int rectangleIndices[6];
	float pi;
	float circleIncrement;
	unsigned int numCircVertices;
	float circleVertices[9 * 180];
	unsigned int EBO;
	unsigned int VBO;
	unsigned int shaderProgramId;
	unsigned int VAO;
	unsigned int VBORect;
	unsigned int VAORect;
	unsigned int VBOCircle;
	unsigned int VAOCircle;
};

void runOpenGL(std::atomic<bool> *run, std::condition_variable *cv,
	std::atomic<bool> *detachController)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(800,800,"Learn OpenGL",NULL,NULL);
	glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);
	if (window == NULL)
	{
		std::cout << "You done fucked up.\n";
		glfwTerminate();
		*detachController = true;
		*run = false;
		cv->notify_one();
		return;
	}
	glfwMakeContextCurrent(window);
	glViewport(0,0,800,800);
	// Initialize renderer
	Renderer renderer;
	// Initialize array of floats that control clear color
	float colors[3] {0.0,1.0,0.0};
	float addOns[3] {0.05,-0.025,0.025};
	while(*run && !glfwWindowShouldClose(window))
	{
		renderer.renderTriangleSetup();
		// Process keypresses
		process_input(window);
		// Rendering commands below
		glClearColor(colors[0], colors[1], colors[2], 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		renderer.renderTriangle();
		renderer.renderRectangle();
		renderer.renderCircle();
		// Swap the buffers
		glfwSwapBuffers(window);
		// Sleep to take load off of my crappy vm
		std::this_thread::sleep_for(std::chrono::milliseconds(60));
		// Poll for events
		glfwPollEvents();
		// Update clearing colors
		colors[0] += addOns[0];
		colors[1] += addOns[1];
		colors[2] += addOns[2];
		if (colors[0] > 1.0 || colors[0] < 0.0)
		{
			addOns[0] *= -1;
			colors[0] += addOns[0];
		}
		if (colors[1] > 1.0 || colors[1] < 0.0)
		{
			addOns[1] *= -1;
			colors[1] += addOns[1];
		}
		if (colors[2] > 1.0 || colors[2] < 0.0)
		{
			addOns[2] *= -1;
			colors[2] += addOns[2];
		}
	}
	if (glfwWindowShouldClose(window))
	{
		*detachController = true;
		*run = false;
		cv->notify_one();
	}
	glfwTerminate();
}

int main()
{
	// Create program controllers
	std::condition_variable cv;
	std::mutex mtx;
	std::unique_lock<std::mutex> lck(mtx);
	std::atomic<bool> run {true};
	std::atomic<bool> detachController {false};
	// Spawn main controller thread
	std::thread mainController(cinEnder,&run,&cv);
	// Do opengl stuff
	std::thread openGLThread(runOpenGL,&run,&cv,&detachController);
	// Waits until input to terminal to close program
	while (run) { cv.wait(lck); }
	if (detachController)
	{
		mainController.detach();
	}
	else
	{
		mainController.join();
	}
	openGLThread.join();
}