#pragma once
#include <Core/Core.h>
#include <Memory/String.h>

/// <summary>
/// Encapsulates the shaders and linked program handles
/// </summary>
class EXPORT ShaderProgram
{
public:
	ShaderProgram(const String& vertexSource, const String& fragmentSource);
	~ShaderProgram();

	/// <summary>
	/// Returns the OpenGL handle for this shader program
	/// </summary>
	/// <returns></returns>
	FORCEINLINE GPU_HANDLE GetProgramHandle() const;
private:
	GPU_HANDLE m_ProgramHandle;
};