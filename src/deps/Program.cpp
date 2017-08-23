#include "Program.hpp"

#include <iostream>
#include <string>

using namespace std;

static auto makeShader(GLenum type, const char* source)
{
	auto shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, nullptr);
	glCompileShader(shader);
	GLint logLength;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
	if(logLength > 1) {
		string what(logLength - 1, '\0');
		glGetShaderInfoLog(shader, logLength, nullptr, &what.front());
		cerr << what << endl;
	}
	return shader;
}

Program::Program()
{
	// Create the vertex shader
	const auto vtxShader = makeShader(GL_VERTEX_SHADER, R"glsl(
		#version 330
		in vec3 vert;
		in vec3 color;
		out vec3 color;

		void main() {
			gl_Position = vec4(vert.x, vert.y, vert.z, 1.0f);
		}
	)glsl");

	// Create the fragment shader
	const auto fragShader = makeShader(GL_FRAGMENT_SHADER, R"glsl(
		#version 330
		in vec3 color;
		out vec4 fragColor;

		void main() {
			fragColor = vec4(color.x, color.y, color.z, 1.0f);
		}
	)glsl");

	// Create the program by linking the vertex and fragment shaders
	const auto prog = glCreateProgram();
	glAttachShader(prog, vtxShader);
	glAttachShader(prog, fragShader);
	glLinkProgram(prog);
	GLint logLenght;
	glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &logLenght);
	if(logLenght > 1) {
		string what(logLenght - 1, '\0');
		glGetProgramInfoLog(prog, logLenght, nullptr, &what.front());
		cerr << what << endl;
	}
	glUseProgram(prog);

	// Clean up shaders
	glDeleteShader(vtxShader);
	glDeleteShader(fragShader);
}
