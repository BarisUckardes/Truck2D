#include "ShaderProgram.h"
#include <Core/Log.h>
#include <GLAD/glad.h>

void _validate_shader(GPU_HANDLE shaderID)
{
	GLint state = 0;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &state);
	if (state == GL_FALSE)
	{
		GLint maxLength = 255;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);

		char* errorLog = new char[maxLength];
		glGetShaderInfoLog(shaderID, maxLength, &maxLength, errorLog);

		LOG("OpenGL", "Shader erorr: %s", errorLog);
	}
}

ShaderProgram::ShaderProgram(const String& vertexSource, const String& fragmentSource)
{
	/*
	* Create shaders
	*/
	GPU_HANDLE vertexShaderHandle = glCreateShader(GL_VERTEX_SHADER);
	GPU_HANDLE fragmentShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
	GPU_HANDLE programHandle = glCreateProgram();

	/*
	* Set shader data
	*/
	const char* vertexSourcePtr = *vertexSource;
	const char* fragmentSourcePtr = *fragmentSource;
	glShaderSource(vertexShaderHandle, 1, &vertexSourcePtr, 0);
	glShaderSource(fragmentShaderHandle, 1, &fragmentSourcePtr, 0);

	/*
	* Compile
	*/
	glCompileShader(vertexShaderHandle);
	glCompileShader(fragmentShaderHandle);
	_validate_shader(vertexShaderHandle);
	_validate_shader(fragmentShaderHandle);

	/*
	* Attach and link program
	*/
	glAttachShader(programHandle, vertexShaderHandle);
	glAttachShader(programHandle, fragmentShaderHandle);
	glLinkProgram(programHandle);

}

ShaderProgram::~ShaderProgram()
{

}

GPU_HANDLE ShaderProgram::GetProgramHandle() const
{
	return m_ProgramHandle;
}
