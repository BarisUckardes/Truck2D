#pragma once
#include <Core/Core.h>
#include <Graphics/Mesh/MeshVertex.h>
#include <Memory/Array.h>

/// <summary>
/// Encapsulates OpenGL vertex array,buffer and index buffers
/// Simple opengl implementation of a entire mesh
/// </summary>
class EXPORT Mesh
{
public:
	Mesh(const Array<MeshVertex>& vertexes, const Array<int>& indexes);
	~Mesh();

	/// <summary>
	/// Returns the vertex array handle
	/// </summary>
	/// <returns></returns>
	FORCEINLINE GPU_HANDLE GetVertexArrayHandle() const;

	/// <summary>
	/// Returns the vertex buffer handle
	/// </summary>
	/// <returns></returns>
	FORCEINLINE GPU_HANDLE GetVertexBufferHandle() const;

	/// <summary>
	/// Returns the index buffer handle
	/// </summary>
	/// <returns></returns>
	FORCEINLINE GPU_HANDLE GetIndexBufferHandle() const;

	/// <summary>
	/// Returns the index count
	/// </summary>
	/// <returns></returns>
	unsigned int GetIndexCount() const;
private:
	GPU_HANDLE m_VertexArrayHandle;
	GPU_HANDLE m_VertexBufferHandle;
	GPU_HANDLE m_IndexBufferHandle;
	unsigned int m_IndexCount;
};