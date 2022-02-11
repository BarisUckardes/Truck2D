#pragma once
#include <Core/Core.h>
#include <Memory/String.h>

/// <summary>
/// Encapsulates OpenGL texture handle and load from disk operations
/// </summary>
class EXPORT Texture2D
{
public:
	Texture2D(const String& path);
	~Texture2D();

	/// <summary>
	/// Returns the OpenGL handle for this texture
	/// </summary>
	/// <returns></returns>
	FORCEINLINE GPU_HANDLE GetTextureHandle() const;
private:
	GPU_HANDLE m_TextureHandle;
};